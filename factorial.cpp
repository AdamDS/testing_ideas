#include <iostream>
using namespace std;

int mult(int a, int b) {
  return a*b;
}

void factorial(int*n,int *m) {
  if(*m>0) {
    *m--;
    cout << *n << " " << *m << endl;
    factorial(mult(*n,*m),*m);
    cout << *n << " " << *m << endl;
  }
}

int main(void) {
  int m = 4;
  int *n;
  n = new int;
  *n = 1;
  factorial(n,m);
  cout << *m << "!" << *n << endl;
  
  return 0;
}
