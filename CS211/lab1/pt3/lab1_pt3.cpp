#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

//prints array passed in
void printArray(const int values[])
{
  for(int x = 0; x < SIZE; x++)
    cout << values[x] << " ";
  cout << endl;
}

//creates array from values in text file
void makeArray(int values[])
{
  ifstream inFile;
  int count = 0;

  inFile.open("data.txt");
  if(!inFile)
    cout << "File not found." << endl;

  else
  {
    while(inFile)
    {
      if(inFile.eof()) 
	break;
      inFile >> values[count];
      count++;
    }
  }
  inFile.close();
}

//returns reversed array
void reverseArray(const int source[], int dest[])
{
  for(int x = 0; x < SIZE; x++)
    dest[x] = source[(SIZE-1)-x];
}

//returns number of values in array that are >= 80 and <= 100
int findGreaterThanEighty(const int values[])
{
  int count = 0;
  for(int x = 0; x < 10; x++)
  {
    if(values[x] >= 80 && values[x] <= 100)
      count++;
  }
  return count;
}

//returns number of values in array that are evenly divisible by 5
int divByFive(const int values[10])
{
  int count = 0;
  for(int x = 0; x < 10; x++)
  {
    if(values[x] % 5 == 0)
      count++;
  }
  return count;
}

//prints the indicies of the values in the array that are evenly divisible by 5
void indexDivByFive(const int values[10])
{
  cout << "Indicies of elements divisible by 5:";

  for(int x = 0; x < SIZE; x++)
  {
    if(values[x] % 5 == 0)
      cout << " " << x;
  }
  cout << endl;
}

//returns the mean (avearge) of all values in the array
double average(const int values[10])
{
  int total = 0;
  for(int x = 0; x < SIZE; x++)
  {
    total += values[x];
  }
  return total/SIZE;
}

//returns the minimum value in the array
int min(const int values[10])
{
  int min = values[0];
  for(int x = 0; x < 10; x++)
  {
    if(values[x] < min)
      min = values[x];
  }
  return min;
}

//asks user for to enter a key value
//searches for the key among the values in the array
//returns true if the value is found
//returns false if the value is not found
bool keySearch(const int values[])
{
  int userInput = 0;
  bool response = 0;

  cout << "Enter a key to search for: ";
  cin >> userInput;
  
  for(int x = 0; x < 10; x++)
  {
    if(values[x] == userInput)
      response = 1;
  }
  return response;
}

int main()
{
  int arrayA[SIZE];
  int arrayB[SIZE];

  makeArray(arrayA);

  reverseArray(arrayA, arrayB);

  printArray(arrayA);
  printArray(arrayB);
  
  cout << findGreaterThanEighty(arrayA) << " are >= 80 and <= 100." << endl;
  cout << divByFive(arrayA) << " are divisible by 5." << endl;
  
  indexDivByFive(arrayA);
  
  cout << fixed << setprecision(1) << average(arrayA) << " is the average of the values in the array." << endl;
  cout << min(arrayA) << " is the minimum value in the array." << endl;

  if(keySearch(arrayA))
    cout << "Key was located in array." << endl;
  else
    cout << "Key not located in array." << endl;

}
