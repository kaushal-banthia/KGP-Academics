
//testing function

int printStr(char *c);
int printInt(int i);
int readInt(int *eP);
int a;
int b = 1;
char c;
char d = 'a';

int mult (int a, int b) {
  int ans;
  int*p;
  printStr(" Called function \n");
  ans = a*b;
  printStr("  Return to function caller\n");
  return ans;
}
int main () {
  int c = 2, d, arr[10];
  int*p;
  int x, y, z;
  int eP;
  printStr("\n Multiplication of two numbers:\n\n");
  printStr("\n    Enter first numbers  : ");
  x = readInt(&eP);
  printStr("    Enter second numbers : ");
  y = readInt(&eP);
  printStr("\n  colling function mult\n");
  z = mult(x,y);
  printStr("\n  Product is equal to : ");
  printInt(z);
  printStr("\n");
  return c;
}