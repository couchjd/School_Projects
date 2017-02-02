#include "fibonacci.h"

int Fibonacci::getFibo(int numIn){
  if(numIn == 0)
    return 0;
  if(numIn == 1)
    return 1;
  return(getFibo(numIn - 2) + getFibo(numIn - 1));
}
/*
bool Fibonacci::isFibo(int numIn){
  for(int x = 0; x <= numIn; x++){
    if(getFibo(x) == numIn)
      return 1;
    if(getFibo(x) > numIn)
      return 0;
  }
  return 0;
}
*/

bool isFibo(int numIn){
  for(int x = 0; x <= numIn; x++){
    if(getFibo(x) == numIn)
      return 1;
    if(getFibo(x) > numIn)
      return 0;
  }
  return 0;
}

