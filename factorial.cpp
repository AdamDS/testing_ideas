#include <iostream>
using namespace std;

//function prototypes
void factorial(int*n,int *m);
int mult(int a, int b);

//Example: 4! = 4*3*2*1 = 24
//*n = 1  *m = 4    cout--1 4
//*n = 4  *m = 3    cout--4 3
//*n = 12 *m = 2    cout--12 2
//*n = 24 *m = 1    cout--24 1

int main(void) {
  int m = 4;
  int *n;
  n = new int;
  *n = 1;
  factorial(&n,&m); //passing addresses
  cout << m << "!" << n << endl;
  
  return 0;
}

int mult(int a, int b) {  return a*b; }

void factorial(int *n,int *m) {
  if(*m>0) {  //if incrementer goes to zero
    *m--;
    cout << *n << " " << *m << endl;
    factorial(&mult(*n,*m),&m);
  }
}
