#include <iostream>
using namespace std;

//function prototypes
int mult(int a, int b);
void factorial_p(int*,int*);
int factorial_i(int);

//Example: 4! = 4*3*2*1 = 24
//*n = 1  *m = 4    cout--1 4
//*n = 4  *m = 3    cout--4 3
//*n = 12 *m = 2    cout--12 2
//*n = 24 *m = 1    cout--24 1

int main(void) {
  int m = 0;
  int n, o;
  while(m>=0) {
    cout << "Enter natural number (<0 exits): ";
    cin >> m;
    n = 1;
    o = m;
    cout << n << " " << m << endl;
    factorial(&n,&m); //passing addresses
    cout << o << "! = " << n << endl;
  }
  return 0;
}

int mult(int a, int b) {  return a*b; }

void factorial_p(int *c,int *d) {
  if(*d>0) {  //if incrementer goes to zero
    cout << *c << " " << *d << endl;
    *c = mult(*c,*d);
    (*d)--;
    factorial(c,d);
  }
}

int factorial_i(int e) {
  if(e>0) {
    cout << e << endl;
    return e*factorial_i(e-1);
  } else {  
    cout << "base" << endl;
    return 1; 
  }
}
