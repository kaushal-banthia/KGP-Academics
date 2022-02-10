// C program to find nth ugly number

// This function divides a by greatest divisible
// power of b
int maxDivide(int a, int b)
{
	while (a % b == 0)
		a = a / b;
	return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);
  if(no==1){
	  return 1;
  }
  return 0;
}

// Function to get the nth ugly number
int getNthUglyNo(int n)
{
	
	int i = 1;
	
	// ugly number count
	int count = 1;

	// Check for all integers untill ugly count
	// becomes n
	while (n > count) {
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}

// Driver Code
int main()
{
	// Function call
  //15th ugly number
    int n = getNthUglyNo(15);
	return 0;
}
