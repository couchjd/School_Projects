#include <iostream>
#include <fstream>
#include <iomanip>
#include "funcs.h"

using namespace std;

int findMax(int values[])
{
  int max = values[0];
  for(int x = 0; x < (sizeof(values))-1; x++)
  {
    if(values[x] > max)
      max = values[x];
  }
  return max;
}

int findMin(int values[])
{
  int min = values[0];
  for(int x = 0; x < (sizeof(values))-1; x++)
  {
    if(values[x] < min)
      min = values[x];
  }
  return min;
}

double findAverage(int A1, int A2, int A3)
{
  return ((A1+A2+A3)/3.0);
}

void processARow(int A1, int A2, int A3, int &min, int &max, double &average)
{
  int values[] = {A1, A2, A3};
  max = findMax(values);
  min = findMin(values);
  average = findAverage(A1, A2, A3);
}
