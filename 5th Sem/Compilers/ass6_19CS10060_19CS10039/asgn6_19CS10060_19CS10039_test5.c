int printStr(char *c);
int readInt(int *ep);
int printInt(int i);

int factorial(int a){
  int ans;
  if(a<=1){
	  if(a<0)ans = -1;
	  else ans = 1;
  }
  else ans = a*factorial(a-1);
  return ans;
}

int main() {
  int a, b[50], *c, p,res;
	printStr("\n\n\n**** Factorial of a numbers ****\n");
	printStr("Enter the number : ");
	a = readInt(&p);
	
	printStr("The value of n! is: ");
	res = factorial(a);
	printInt(res);
	printStr("\n");	
	return 0;  
}