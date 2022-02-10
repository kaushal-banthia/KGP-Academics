/*
COMPILERS LAB ASSIGNMENT 5
GROUP 18
SUNANDA MANDAL|19CS10060
KAUSHAL BANTHIA|19CS10039
*/

// start of header file
# ifndef _TRANSLATOR_H
# define _TRANSLATOR_H

# include <bits/stdc++.h>

#define CHAR_SIZE          1
#define INT_SIZE           4
#define DOUBLE_SIZE        8
#define POINTER_SIZE       4

extern  char* yytext;
extern  int yyparse();

using namespace std;


class sym;                                                  // an entry in Symbol Table
class quad;                                                 // a single entry in the quad Array
class label;                                                // a single label entry in the label table
class symbolTable;                                             // Symbol Table
class basicType;                                            // the basic type data
class quadArray;                                            // the Array of quads
class symboltype;                                           // the type of a symbol in ST
class Expression;                                           // the expression type data storage


/*************************** Global Variables ***************************/

extern symbolTable* ST;                                     // denotes the current Symbol Table
extern symbolTable* globalST;                               // denotes the Global Symbol Table
extern symbolTable* parST;                                  // denotes the Parent of the current Symbol Table
extern sym* currSymbolPtr;                                  // denotes the latest encountered symbol
extern quadArray Q;                                         // denotes the quad Array
extern basicType bt;                                        // denotes the Type ST
extern long long int table_count;                           // denotes count of nested tables
extern bool debug_on;                                       // bool for printing debug output
extern string loop_name;                                    // get the name of the loop
extern vector<label>label_table;                            // table to store the labels

class symboltype;

/*************************** Definition of symbol type ***************************/
class symboltype 
{
    public:
        string type;                                        // string for storing the type of symbol
        symboltype* arrtype;                                // store the type of array recursively
        int width;                                          // stores the size of Array, if array found else it is 1
        
        // Constructor
        symboltype(string type , symboltype* ptr = NULL, int width = 1);                         
};

/*************************** Definition of symbol ***************************/
class sym
{
	public:
        string name;                                        // symbol name
        symboltype *type;                                   // symbol type
        string initial_value;                               // Symbol initial values
        string category;                                    // global, local or param
        int size, offset;                                   // symbol size and offset
        symbolTable *nested;                                // pointer to nested ST
        string val;                                         // symbol's initial value (if specified)

        // constructor
        sym (string _name, string _type = "int", symboltype* ptr = NULL, int width = 0);
        sym* update(symboltype*);  
        sym* link_to_symbolTable(symbolTable *t);                          // update fields of existing entry.
};

/*************************** Definition of label ***************************/
class label
{
    public:
        string name;                                        // label name
        int addr;                                           // the address to which the label is pointing towards
        list<int> nextlist;                                 // stores a list of the dangling goto statements present

        // Constructor
        label(string _name, int _addr = -1);
};

/*************************** Definition of symbol table ***************************/
class symbolTable 
{                                                           // class to store the symbol table
    public:
        string name;                                        // Symbol table name
        int count;                                          // number of temporary variables
        list<sym> table;                                    // table of symbols
        symbolTable* parent;                                // parent symbol table
        map <string, int>ar;                                // activation record

        // Constructor
        symbolTable (string name="NULL");

        void update();                                      // for updating the current symbol table
        void print();                                       // for printing the current symbol table
        sym* lookup (string);                               // Look up a symbol
};

/*************************** Definition of quad ***************************/
class quad 
{
    public:
        string res, op, arg1, arg2; 

        void print();	
        void type1();                                       // print binary operator
        void type2();                                       // print jumps & relops

        // Constructor Overloading
        quad (string res, int , string op = "=", string arg2 = "");
        quad (string res, float , string op = "=", string arg2 = "");
        quad (string res, string , string op = "=", string arg2 = "");
};

/*************************** Definition of quad array ***************************/
class quadArray 
{
    public:
        vector<quad> Array;                                 // array of quads
        void print();                                       // function for printing the quadArray
};

/*************************** Definition of basic type ***************************/
class basicType 
{
    public:
        vector<string> type;                                // type name
        vector<int> size;                                   // type size

        void addType(string _type, int _size);              // function to add a basictype
};

/*************************** Definition of Expression ***************************/
struct Expression 
{
    sym* loc;                                               // pointer to the symbol table entry
    string type;                                            // to store whether the expression is of type int or bool or float or char
    list<int> truelist, falselist, nextlist;                // truelist and falselist for boolean expressions and nextlist for statement expressions
};

/*************************** Definition of Array ***************************/
struct Array
{
    string atype;                                           // type of array
    symboltype* type;                                       // type of subarry
    sym* loc;                                               // Location for computing address of array
    sym* Array;                                             // symbol table entry pointer
};

/*************************** Definition of Statement ***************************/
struct Statement
{
    list<int> nextlist;                                     // nextlist for Statement with dangling exits
};

/*************************** Helper Functions ***************************/
void emit(string, string, string arg1 = "", string arg2 = "");  
void emit(string, string, int, string arg2 = "");		  
void emit(string, string, float, string arg2 = "");   

sym* gentemp (symboltype* , string init = "");

void backpatch (list <int> , int);                          // function for backpatching the dangling instructions

list<int> makelist (int);                                   // function for making a list with an int address
list<int> merge (list<int> &l1, list <int> &l2);            // merge 2 lists into one

label* find_label(string name);                             // function for finding the label using name

/*************************** Functions relating to types ***************************/
Expression* convertIntToBool(Expression*);                  // int expression to boolean conversion
Expression* convertBoolToInt(Expression*);                  // boolean expression to int conversion
string convertIntToString(int);                             // integer to string conversion
string convertFloatToString(float);                         // float to string conversion
sym* convertType(sym*, string);                             // type conversion

/*************************** Functions relating to Symbol Table ***************************/
bool compareSymbolType(sym* &s1, sym* &s2);                 // check if two symbol table entries have the same type
bool compareSymbolType(symboltype*, symboltype*);           // check if two symbol type objects have the same type
int computeSize (symboltype *);                             // calculation of the size of the current ST
void changeTable (symbolTable* );                           // change current ST

int nextinstr();                                            // return next instruction

int computeSizeSymbolType(symboltype*);                     // Calculate size of any symbol type 
string printType(symboltype *);                             // print type of symbol
void generateSpaces(int);                                   // generate spaces

# endif                                                     // end of header file