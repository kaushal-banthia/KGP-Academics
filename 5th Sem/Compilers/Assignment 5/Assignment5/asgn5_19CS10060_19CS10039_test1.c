//declarations of variables(int, float, char)
//multidimensional arrays 1D array, 2D array, 
//functions
//arithmetic operations

// global declarations
int x=10,q;
float y=9.8, p;
char c;
int arr1[10];	// 1D array declaration
float arr2[5][10];	// 2D array declaration
int *ptr;	//pointer declaration
void division(int i, float d); //function declaration		

void main()
{
	// Variable Declaration
	int a = 120;
	int b = 17,r1,r2,r3,r4,r5,r6,r7;
	char ch='c', d = 'a'; // character definitions

	// Arithmetic Operations
	r1 = x + b;
	r2 = x - b;
	r3 = x * b;
	r4 = x / b;
	r5 = x % b;
	r6 = x & b;
	r7 = x | b;
	y = a<< 2;
	x = b >> 1;

	return 0;
}