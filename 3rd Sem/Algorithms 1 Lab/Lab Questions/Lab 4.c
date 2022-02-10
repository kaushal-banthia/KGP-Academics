#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
char * symbol;
int frequency;
struct Node * next;
struct Node * left;
struct Node * right;
}
Node;

Node* newnode(char *symbol, int num);
Node *insert(Node *root, char *symbol, int num);
void print(Node *root);
Node *supernode(Node *root);
void preOrder(Node* root);

Node *temp1 = NULL;
Node *temp2 = NULL;

int main()
{
    //PART I BEGINS
    FILE *f;
    f = fopen("log.txt", "r");
    if (f == NULL)
        return -1;
    int n;
    fscanf(f, "%d", &n);

    int freq[36];
    for (int i = 0; i < 36; i++)
    {
        freq[i] = 0;
    }

    char words[n][100];
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%s", words[i]);
        int len = strlen(words[i]);
        for (int j = 0; j < len; j++)
        {
            if ((int)words[i][j] <= 122 && (int)words[i][j] >= 97)
            freq[((int)words[i][j])-97]++;
        else
            freq[((int)words[i][j])-48+26]++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c=%d,", 'a'+i, freq[i]);
    }
    for (int i = 26; i < 35; i++)
    {
        printf("%c=%d,", '0'+i-26, freq[i]);
    }
    printf("9=%d\n", freq[35]);

    //PART II BEGINGS

    Node *root = NULL;
    for (int i = 0; i < 26; i++)
        root = insert(root, 'a'+i, freq[i]);
    for (int i = 26; i <36; i++)
        root = insert(root, '0'+i-26, freq[i]);
    root = supernode(root);
    preOrder(root);
}

Node* newnode(char *symbol, int num)
{
    Node* temp = (Node *) malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->symbol = symbol;
    temp->frequency = num;
    temp->next = NULL;
    return temp;
}

Node *insert(Node *root, char *symbol, int num)
{
    if (root == NULL)
        return newnode(symbol, num);

    if (root->frequency > num)//root frequency is more
    {
        if (symbol >= 58 && symbol <= 96)//supernode
        {
            Node *super = newnode(symbol, num);
            super->right = temp2;
            super->left = temp1;
            super->next = root;
            return super;
        }
        Node *temp = newnode(symbol, num);
        temp->next = root;
        return temp;
    }
    else if (root->frequency < num)//incoming frequency is more
    {
        root->next = insert(root->next, symbol, num);
        return root;
    }

    else//both frequencies are same
    {
        if (symbol >= 58 && symbol <= 96)//supernode
        {
            //case1 root is supernode
            if (root->symbol >= 58 && root->symbol <= 96)//root is also supernode
            {
                Node *super = newnode(symbol, num);
                super->right = temp2;
                super->left = temp1;
                super->next = root;
                return super;
            }
            //case2 root is normal
            else
            {
                Node *trav = root;
                while(trav->next != NULL && trav->next->frequency == num)
                    trav = trav->next;
                Node *super = newnode(symbol, num);
                super->right = temp2;
                super->left = temp1;
                super->next = trav->next;
                trav->next = super;
                return root;
            }
        }

        //case1
        //root has number as symbol and newnode has letter ->root will remain as root
        if (root->symbol >= 48 && root->symbol <= 57 && symbol >= 97 && symbol <= 122)
        {
            Node *temp = newnode(symbol, num);
            root->next = temp;
            return root;
        }
        //case2
        //root has letter as symbol and newnode has number ->root will be exchanged
        else if (root->symbol >= 97 && root->symbol <= 122 && symbol >= 48 && symbol <= 57)
        {
            Node* temp = newnode(symbol, num);
            temp->next = root;
            return temp;
        }
        //case3
        //root has letter and newnode has letter OR root has number and newnode has number
        else
        {
            if (root->symbol > symbol)
            {
                //no exchange
                Node *temp = newnode(symbol, num);
                root->next = temp;
                return root;
            }
            else
            {
                //exchange
                Node *temp = newnode(symbol, num);
                temp->next = root;
                return temp;
            }
        }
    }
}

void print(Node *root)
{
    Node *trav = root;
    while(trav != NULL)
    {
        printf("%c occurs %d times\n", trav->symbol, trav->frequency);
        trav = trav->next;
    }
}


Node *supernode(Node *root)
{
    char* symbol = ':';
    while(root->next != NULL)
    {
        temp1 = root;
        temp2 = root->next;
        root = temp2->next;
        int num = (temp1->frequency) + (temp2->frequency);
        root = insert(root, symbol, num);
        symbol++;
    }
    return root;
}

void preOrder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->frequency);
    preOrder(root->left);
    preOrder(root->right);
}
