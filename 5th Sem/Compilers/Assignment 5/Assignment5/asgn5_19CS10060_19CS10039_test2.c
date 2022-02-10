// typecasting and pointers
void twiceAndHalf(int* a, int* b) //pointers
{
	*a = (*a) * 2;
	*b = (*b)/2;
	return;
}

int division(float a, int b)
{
	float res;
    int resint;
	res = a/(float)b; // type casting int -> float 
    resint = res; // type casting float -> int
	return res;
}

int main()
{
	int q=0,r=0;
	float x=20.5;
	q = division(x,3);
	r=10;
	twiceAndHalf(&q,&r);
	return;
}