#include <iostream>
#include <fstream>
#include <iomanip>

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

int main()
{
  ifstream inFile;
  string id;
  int A1 = 0;
  int A2 = 0;
  int A3 = 0;
  int min = 0;
  int max = 0;
  double average = 0.0;

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

      processARow(A1, A2, A3, min, max, average);
      
      cout << id << "\t\t" << A1 << '\t' << A2 << '\t' << A3 << '\t' << 
	min << '\t' <<  max << '\t' << fixed << setprecision(1) << average << endl;
    }
  }
  inFile.close();
}
