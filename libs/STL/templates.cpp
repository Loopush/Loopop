//g++ -Wall -S templates.cpp   (parameter -S outputs .asm !!!)

#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) {
  return (a>b?a:b);
}

template <class T, class U>
T GetMin (T a, U b) {
  return (a<b?a:b);
}

int main () {
  int i=5, j=6, k;
  double l=10, m=4.2, n;
  k=GetMax(i,j);
  n=GetMax(l,m);
  cout << k << endl;
  cout << n << endl;
  cout << GetMin(m,j) << endl;
  return 0;
}