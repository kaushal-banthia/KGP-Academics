// nested if else and recursive functions  
int factorial(int n){
	if(n<2){
		if(n<0)
			return -1;
		return 1;	
	}
	return n*factorial(n-1);
		
}
int main()  
{  
    int a, b, fact;
    int flag=2;
    if(flag==0)
    {
    	a=100;
    	b=25;
    }
    else
    {
    	a=20;
    	if(flag==1)   // nested if else
    		b=5;
    	else
    		b=4;
    }
    fact = factorial(5);   // recursive function call
	(1) ? printf("n>=5") : printf("n<5");
    return 0;  
}  