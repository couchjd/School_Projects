#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int size(int inArray[])
{
  return(sizeof(inArray));
}

int calculateMax(int A1, int A2, int A3)
{
  int values[] = {A1, A2, A3};

  int max = values[0];
  
  for(int x = 0; x < (size(values))-1; x++)
  {
    if(values[x] > max)
      max = values[x];
  }
  return max;
}

int calculateMin(int A1, int A2, int A3)
{
  int values[3] = {A1, A2, A3};

  int min = values[0];
  for(int x = 0; x < (size(values))-1; x++)
  {
    if(values[x] < min)
      min = values[x];
  }
  return min;
}

double calculateAvg(int A1, int A2, int A3)
{
  return ((A1+A2+A3)/3.0);
}

int main()
{
  ifstream inFile;
  string id;
  int A1 = 0;
  int A2 = 0;
  int A3 = 0;

  inFile.open("data.txt");
  if(!inFile)
    cout << "File not found." << endl;

  else
  {
    cout << "ID" << "\t\t" << "A1" << '\t' << "A2" << '\t' << "A3" << 
      '\t' << "Min" << '\t' << "Max" << '\t' << "Avg" << endl;
    cout << "-------------------------------------------------------------" << endl;

    while(inFile)
    {
      if(inFile.eof()) 
	break;

      inFile >> id >> A1 >> A2 >> A3;

      cout << id << "\t\t" << A1 << '\t' << A2 << '\t' << A3 << '\t' << fixed << setprecision(1) <<
	calculateMin(A1, A2, A3) << '\t' <<  calculateMax(A1, A2, A3) << '\t' << calculateAvg(A1, A2, A3) << endl;
    }
  }
  inFile.close();
}
