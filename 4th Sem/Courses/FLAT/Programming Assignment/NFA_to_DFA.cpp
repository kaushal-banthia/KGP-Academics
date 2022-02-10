
// Kaushal Banthia
// 19CS10039

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef uint32_t* set_of_states; // Set of states are array of unsigned ints (bit level storage)

class NFA
{
    public:
    int m; // Number of alphabets in NFA
    int n; // Number of states in NFA
    uint32_t start_states; // Start states in the NFA as an unsigned int (bit level storage)
    uint32_t final_states; // Final states in the NFA as an unsigned int (bit level storage)
    uint32_t **delta; // Transition function of the NFA
};

class DFA
{
    public:
    uint32_t n; // Number of states in DFA
    int m; // Number of alphabets in DFA
    int start_state; // Start state of the DFA as integer
    set_of_states final_states; // Final States of the DFA as an array of unsigned ints (bit level storage)
    uint32_t **delta; // Transition function of the DFA
    uint32_t num_final_states; // Number of final states in the DFA
};

NFA readNFA(string name_); // Reads the input NFA
void printNFA(NFA N); // Prints the given NFA
void printstates(uint32_t n); // Prints the states that the unsigned integer denotes using bit level storage
void printdelta(uint32_t n, uint32_t m, uint32_t **delta, int from_dfa = 1); // Prints the transition function of the finite automata
DFA subsetcons(NFA N); // Constructs DFA from NFA using subset construction
void printDFA(DFA D); // Prints the given DFA
set_of_states findreachable(DFA D); // Finds the set of reachable states using Depth First Search
set_of_states DFS(DFA D, uint32_t current_state, set_of_states R); // An implementation of Depth First Search
void print_set_of_states(set_of_states S, uint32_t n); // Prints the set of states that array of unsigned integers denotes using bit level storage
DFA rmunreachable(DFA D, set_of_states R, int choose = 0); // Returns equivalent DFA with unreachable states removed
void printReducedDFA(DFA D, uint32_t n, int choose); // Prints the reduced DFA
uint32_t **findequiv(DFA D_dash); // Finds the set of equivalent states in a DFA
DFA collapse(DFA D_dash, uint32_t **M); // Returns the minimal DFA after collapsing the equivalent states

int main()
{
    cout<<"Enter the name of the file that stores the information about the input NFA N"<<endl;
    string name_;
    cin>>name_;

    NFA N = readNFA(name_);
    printNFA(N);
    DFA D = subsetcons(N);
    printDFA(D);
    set_of_states R = findreachable(D);
    DFA D_dash = rmunreachable(D,R);
    uint32_t **M = findequiv(D_dash);
    DFA D_dash_dash = collapse(D_dash, M);
}

NFA readNFA(string name_)
{
    NFA N;
    fstream file(name_);
    string line;

    getline(file, line);
    N.n = stoi(line);

    getline(file, line);
    N.m = stoi(line);

    getline(file, line);
    N.start_states = 0;
    stringstream ss_start(line);
    while(1)
    {
        string start_state;
        ss_start >> start_state;
        if (start_state == "-1")
            break;
        int state = stoi(start_state);
        N.start_states |= (1U << state);
    }

    getline(file, line);
    N.final_states = 0;
    stringstream ss_final(line);
    while(1)
    {
        string final_state;
        ss_final >> final_state;
        if (final_state == "-1")
            break;
        int state = stoi(final_state);
        N.final_states |= (1U << state);
    }

    N.delta = new uint32_t*[N.n]; 
    for (uint32_t i = 0; i < N.n; i++)
    {
        N.delta[i] = new uint32_t[N.m]; 
    }

    for (uint32_t i = 0; i < N.n; i++)
    {
        for (uint32_t j = 0; j < N.m; j++)
        {
            N.delta[i][j] = 0;
        }
    }

    while (getline (file, line))
    {
        if (line == "-1")
            break;
        stringstream ss_delta(line);
        string p, a, q;
        ss_delta >> p;
        ss_delta >> a;
        ss_delta >> q;
        N.delta[(uint32_t)stoi(p)][(uint32_t)stoi(a)] |= (1U << (uint32_t)stoi(q));
    }
    
    file.close();
    return N;
}

void printNFA(NFA N)
{
    cout<<endl<<"+++ Input NFA"<<endl;
    cout<<"    Number of states: "<<N.n<<endl;
    cout<<"    Input alphabet: {";
    for (uint32_t i = 0; i < N.m; i++)
    {
        if (i == 0)
            cout<<i;
        else
            cout<<','<<i;
    }
    cout<<"}"<<endl;

    cout<<"    Start states: ";
    printstates(N.start_states);

    cout<<"    Final states: ";
    printstates(N.final_states);

    cout<<"    Transition function"<<endl;
    printdelta(N.n, N.m, N.delta, 0);
}

void printstates(uint32_t n) 
{
    int flag = 0;
    cout<<"{";
    for (int j = 0; j < 32; j++)
    {
        if (n & (1U << j))
        {
            if (flag == 0)
            {
                cout<<j;
                flag = 1;
            }
            else
                cout<<','<<j;
        }
    }
    cout<<"}"<<endl;
}

void printdelta(uint32_t n, uint32_t m, uint32_t **delta, int from_dfa)
{
    for (uint32_t i = 0; i < n; i++)
    {
        for (uint32_t j = 0; j < m; j++)
        {
            if (delta[i][j] != 0)
            {
                cout<<"        Delta("<<i<<','<<j<<") = ";
                if (from_dfa)
                    cout<<delta[i][j]<<endl;
                else
                    printstates(delta[i][j]);
            }
            else
            {
                cout<<"        Delta("<<i<<','<<j<<") = {}";
                cout<<endl;
            }
        }
    }
}

DFA subsetcons(NFA N)
{
    DFA D;
    D.start_state = N.start_states;
    D.n = (1U<<N.n);
    D.m = N.m;
    D.delta = new uint32_t*[D.n];
    for (uint32_t i = 0; i < D.n; i++)
    {
        D.delta[i] = new uint32_t[D.m];
    }

    D.num_final_states = 0;
    D.final_states = new uint32_t[D.n/32 + 1];

    for (uint32_t x = 0; x < D.n; x++) // for every state in DFA
    {
        for (int k = 0; k < D.m; k++) // alphabet
        {
            uint32_t to_state = 0;
            for (int j = 0; j < N.n; j++) // which is 0 and 1
            {
                if ((x & (1U << j)) != 0)
                    to_state |= N.delta[j][k];
            }
            D.delta[x][k] = to_state;
        }
        
        uint32_t pos = x/32;
        if (x%32 == 0)
            D.final_states[pos] = 0;
        if ((x & N.final_states))
        {
            // x is the new final state
            D.final_states[pos] |= (1U << x%32);
            D.num_final_states++;
        }
    }
    return D;
}

void printDFA(DFA D)
{
    cout<<endl<<"+++ Converted DFA"<<endl;
    cout<<"    Number of states: "<<D.n<<endl;
    cout<<"    Input alphabet: {";
    for (uint32_t i = 0; i < D.m; i++)
    {
        if (i == 0)
            cout<<i;
        else
            cout<<','<<i;
    }
    cout<<"}"<<endl;

    cout<<"    Start state: "<<D.start_state<<endl;
    cout<<"    "<<D.num_final_states<<" final states"<<endl;
    cout<<"    Transition function";
    if (D.n <= (1U<<5))
    {
        cout<<endl;
        printdelta(D.n, D.m, D.delta);
    }
    else
    {
        cout<<": Skipped"<<endl;
    }
}

set_of_states findreachable(DFA D)
{
    set_of_states R = new uint32_t[D.n/32 + 1];
    for (uint32_t i = 0; i < D.n/32 + 1; i++)
    {
        R[i] = 0;
    }
    R = DFS(D, D.start_state, R); //calling DFS

    cout<<endl<<"+++ Reachable states: {";
    print_set_of_states(R, D.n/32 + 1);
    cout<<'}'<<endl;
    return R;
}

set_of_states DFS(DFA D, uint32_t current_state, set_of_states R) 
{
    if (R[current_state/32] & (1U << (current_state%32)))
        return R;
    else
        R[current_state/32] |= (1U << (current_state%32));

    for (int i = 0; i < D.m; i++)
    {
        R = DFS(D, D.delta[current_state][i], R);
    }
    return R;
}

void print_set_of_states(set_of_states S, uint32_t n)
{
    uint32_t i, j;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((S[i] & (1U << j)))
            {
                cout<<32*i+j;
                j++;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    for (; i < n; i++)
    {
        for (; j < 32; j++)
        {
            if ((S[i] & (1U << j)))
                cout<<","<<32*i+j;
        }
        j=0;
    }
}

DFA rmunreachable(DFA D, set_of_states R, int choose)
{
    DFA D_dash;
    D_dash.n = 0;
    D_dash.m = D.m;
    D_dash.start_state = D.start_state;

    for (uint32_t i = 0; i < D.n/32 + 1; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if ((R[i] & (1U << j)))
                D_dash.n++; //new number of state in the reduced DFA
        }
    }

    D_dash.final_states = new uint32_t[D.n/32 + 1];
    D_dash.num_final_states = 0;

    D_dash.delta = new uint32_t*[D_dash.n];

    uint32_t *renumbering = new uint32_t[D.n];
    uint32_t replacement = 0;
    
    for (uint32_t i = 0; i < D.n/32 + 1; i++)
    {
        D_dash.final_states[i] = R[i] & D.final_states[i]; // make new final states array

        for (int j = 0; j < 32; j++)
        {
            if ((R[i] & (1U << j)))
            {
                renumbering[32*i + j] = replacement; // making a renumbering array
                D_dash.delta[replacement] = D.delta[32*i + j]; // makes new delta function
                
                replacement++;
            }
        }
    }
    
    D_dash.start_state = renumbering[D_dash.start_state];
    set_of_states final_states = new uint32_t[D_dash.n/32+1];

    for (uint32_t i = 0; i < D_dash.n/32 + 1; i++)
    {
        final_states[i] = 0;
    }

    for (uint32_t i = 0; i < D.n/32 + 1; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            // renumbering the final states
            if ((D_dash.final_states[i] & (1U << j)))
            {
                uint32_t r = renumbering[32*i+j];
                final_states[r/32] |= (1U << (r%32));
            }
        }
    }
    D_dash.final_states = final_states;

    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        for (int k = 0 ; k < D_dash.m; k++)
        {
            D_dash.delta[i][k] = renumbering[D_dash.delta[i][k]];
        }
    }
    printReducedDFA(D_dash, D_dash.n, choose);
    return D_dash;
}

void printReducedDFA(DFA D, uint32_t n, int choose)
{
    if (choose == 0) // for reduced DFA
        cout<<endl<<"+++ Reduced DFA after removing unreachable states"<<endl;
    else if (choose == 1) // for collapsed DFA
        cout<<endl<<"+++ Reduced DFA after collapsing equivalent states"<<endl;
    cout<<"    Number of states: "<<D.n<<endl;
    cout<<"    Input alphabet: {";
    for (uint32_t i = 0; i < D.m; i++)
    {
        if (i == 0)
            cout<<i;
        else
            cout<<','<<i;
    }
    cout<<"}"<<endl;
    
    cout<<"    Start state: "<<D.start_state<<endl;
    cout<<"    Final states: {";
    print_set_of_states(D.final_states, n/32 + 1);
    cout<<'}'<<endl;

    cout<<"    Transition function"<<endl;
    cout<<"    a\\p|";
    for (uint32_t i = 0; i < D.n; i++)
    {
        if (i < 10)
            cout<<"  "<<i;
        else
            cout<<" "<<i;
    }
    cout<<endl;

    cout<<"    ---+";
    for (uint32_t i = 0; i < D.n; i++)
    {
        cout<<"---";
    }
    cout<<endl;

    for (int j = 0; j < D.m; j++)
    {
        cout<<"     "<<j<<" |";
        for (uint32_t i = 0; i < D.n; i++)
        {
            if (D.delta[i][j] < 10)
                cout<<"  "<<D.delta[i][j];
            else
                cout<<" "<<D.delta[i][j];
        }
        cout<<endl;
    }
}

uint32_t **findequiv(DFA D_dash)
{
    // Marked pairs (whose M[i][j] is set to 1) are not equivalent
    // Unmarked pairs (whose M[i][j] is set to 0) are equivalent
    uint32_t **M = new uint32_t*[D_dash.n];
    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        M[i] = new uint32_t[D_dash.n];
        for (uint32_t j = 0; j < D_dash.n; j++)
        {
            M[i][j] = 0; // Unmarked Initially
        }
    }

    // Step 1: Mark those pairs in which one is final state and the other isn't
    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        for (uint32_t j = i+1; j < D_dash.n; j++)
        {
            // i and j are states in the DFA
            bool i_is_final = ((D_dash.final_states[i/32] & (1U << (i%32))) != 0);
            bool j_is_final = ((D_dash.final_states[j/32] & (1U << (j%32))) != 0);
            
            if (i_is_final != j_is_final) // mark this pair (not equivalent)
            {
                M[i][j] = 1;
                M[j][i] = 1;
            }
        }
    }

    // Step 2: Mark those pairs whose delta step on the same alphabet is marked.
    // If for all alphabets, the delta step isnt marked then it remains unmarked
    uint32_t num_changes;
    do
    {
        num_changes = 0;
        for (uint32_t i = 0; i < D_dash.n; i++)
        {
            for (uint32_t j = i+1; j < D_dash.n; j++)
            {
                // i and j are states in the DFA
                for (int k = 0; k < D_dash.m; k++)
                {
                    if (M[i][j] != 1 && M[D_dash.delta[i][k]][D_dash.delta[j][k]] == 1) // mark this pair (not equivalent)
                    {
                        M[i][j] = 1;
                        M[j][i] = 1;
                        num_changes++;
                        break;
                    }
                }
            }
        }
    }
    while (num_changes != 0); // run this loop on the whole matrix until no more changes are made
    return M;
}

DFA collapse(DFA D_dash, uint32_t **M)
{
    cout<<endl<<"+++ Equivalent states"<<endl;

    uint32_t *group_number = new uint32_t[D_dash.n];
    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        group_number[i] = i;
    }
    
    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        for (uint32_t j = i+1; j < D_dash.n; j++)
        {
            if (M[i][j] == 0 && group_number[j] == j)
                group_number[j] = i;
        }
    }

    uint32_t max_group_number = 0;
    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        max_group_number = max_group_number > group_number[i] ? max_group_number : group_number[i];
    }
    max_group_number++;

    set_of_states *groups = new uint32_t*[max_group_number];
    for (uint32_t i = 0; i < max_group_number; i++)
    {
        groups[i] = new uint32_t[D_dash.n/32 + 1];
        for (uint32_t j = 0; j < D_dash.n/32 + 1; j++)
        {
            groups[i][j] = 0;
        }
    }

    for (uint32_t i = 0; i < D_dash.n; i++)
    {
        groups[group_number[i]][i/32] |= (1U << (i%32));
    }

    // reordering of the groups
    int flag;
    bool swap_states = false;
    uint32_t index;
    uint32_t temp_max_group_number;
    for (uint32_t i = 0; i < max_group_number; i++)
    {
        flag = 0;
        for (uint32_t j = 0; j < D_dash.n/32+1; j++)
        {
            if (groups[i][j] != 0)
            {
                if (swap_states == true)
                {
                    uint32_t *temp = new uint32_t[D_dash.n/32+1];
                    temp = groups[i];
                    groups[i] = groups[index];
                    groups[index] = temp;

                    for (uint32_t x = 0; x < D_dash.n/32+1; x++)
                    {
                        for (uint32_t y = 0; y < 32; y++)
                        {
                            if ((groups[index][x] & (1U << y)))
                                group_number[32*x+y] = index;
                        }
                    }

                    i = index;
                    swap_states = false;
                }
                flag = 1;
                temp_max_group_number = i;
                break;
            }
        }
        if (flag == 0 && swap_states == false) // no state present in this group
        {
            index = i;
            swap_states = true;
        }
    }
    max_group_number = temp_max_group_number+1;

    for (uint32_t i = 0; i < max_group_number; i++)
    {
        if (i < 10)
            cout<<"    Group  "<<i<<": {";
        else
            cout<<"    Group "<<i<<": {";
        print_set_of_states(groups[i], D_dash.n/32 + 1);
        cout<<"}"<<endl;
    }

    set_of_states not_equivalent_states = new uint32_t[D_dash.n/32+1]; 
    for (uint32_t i = 0; i < D_dash.n/32 + 1; i++)
    {
        not_equivalent_states[i] = 0;
    }

    for (uint32_t i = 0; i < max_group_number; i++)
    {
        not_equivalent_states[i/32] |= (1U << (i%32)); // finding set of all non equivalent states
    }

    D_dash.start_state = group_number[D_dash.start_state]; // setting the new start state

    set_of_states final_states = new uint32_t[D_dash.n/32+1];
    for (uint32_t i = 0 ; i < D_dash.n/32+1; i++)
    {
        final_states[i] = 0;
    }

    for (uint32_t i = 0 ; i < D_dash.n/32+1; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if ((D_dash.final_states[i] & (1U << j)))
            {
                uint32_t new_group = group_number[32*i+j];
                final_states[new_group/32] |= (1U << (new_group%32));
            }
        }
    }
    D_dash.final_states = final_states; // setting the new final states

    for (uint32_t i = 0; i < max_group_number; i++)
    {
        int flag = 0;
        for (uint32_t j = 0; j < D_dash.n/32+1; j++)
        {
            for (int k = 0; k < 32; k++)
            {
                if ((groups[i][j] & (1U << k)))
                {
                    flag = 1;
                    for (int m = 0; m < D_dash.m; m++)
                    {

                        D_dash.delta[i][m] = group_number[D_dash.delta[32*j+k][m]]; // setting the new delta function
                    }
                    break;
                }
            }
            if (flag == 1)
                break;
        }
    }
    return rmunreachable(D_dash, not_equivalent_states, 1);
}