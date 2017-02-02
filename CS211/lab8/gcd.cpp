#include "gcd.h"

int GCD::gcd(int x, int y){
  if(y == 0)
    return x;
  return gcd(y, x%y);
}
