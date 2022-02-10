int printStr(char *b);
int printInt(int i);
int readInt(int *eP);

int main () {
    int eP;
    printStr("\n Print diamond pattern  \n");    
    printStr("Ennter size of the middle");

    int b,n,i,j,k;
    n = readInt(&eP);

    for (k = 1; k <= n; k++)
	{
		for (b = 1; b <= n-k; b++)
		printStr(" ");

		for (b = 1; b <= 2*k-1; b++)
		printStr("*");

		printStr("\n");
	}

	for (k = 1; k <= n - 1; k++)
	{
		for (b = 1; b <= k; b++)
		printStr(" ");

		for (b = 1 ; b <= 2*(n-k)-1; b++)
		printStr("*");

		printStr("\n");
	}


    return 0;
}