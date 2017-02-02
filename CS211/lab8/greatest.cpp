#include "fibonacci.h"
#include "gcd.h"
#include <iostream>

int main(){
  int number, x, y;

  cout << "Enter two integers: ";
  cin >> x >> y;
  cout << "GCD is: " <<  GCD::gcd(x, y) << endl;
  return 0;
}
