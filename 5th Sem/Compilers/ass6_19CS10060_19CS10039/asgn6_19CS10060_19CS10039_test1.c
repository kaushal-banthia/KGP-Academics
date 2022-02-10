int printInt(int num);
int printStr(char * c);
int readInt(int *eP);
int main()
{
    int a,b;
    //error pointer
    int *p;
    int  err;
    err = -10;
    p = &err;
    //testing print str function
    printStr("\n\n\n********* Multiplying two numbers a and b *********\n");
    printStr("a = ");
    //esting read int function
    a = readInt(p);
    printStr("b = ");
    b = readInt(p);
    printStr("Product = ");
    //testing print int function
    printInt(a*b);
    printStr("\n");
    return 0;
}