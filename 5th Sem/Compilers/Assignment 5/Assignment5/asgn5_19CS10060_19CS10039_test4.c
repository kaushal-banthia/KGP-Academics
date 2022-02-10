// function calling and conditional statements (ternery and if-else)
char grade(int n) 
{
   char ans;
    if(n>90)
		ans = 'A';
	else if(n>60 && n<=90)
		ans = 'B';
	else if(n>30)
		ans = 'P';
	else
		ans = 'F';
   return ans;
}

int min(int x, int y) 
{
   int ans;
   ans = x > y ? y : x; // ternery
   return ans;
}

int max(int x, int y) 
{
   int ans;
   ans = x>y ? x : y; // ternery
   return ans;
}

int a;

int cal(int a, int b){
	int i, j, d;
	i = min(a, b);
	j = max(a, b);
	d = j - i;
	return d;
}

int main(){
	int a, b, d;
	a = 10, b = 5;
	d = cal(a,b);
	int n=75;
	char result = grade(n);
	if(result=='A'){
		printf("Excellent!!");
	}
	else if(result=='B'){
		printf("Fair!!");	
	}
	return 0;
}