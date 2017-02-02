#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Course.h"
#include "Person.h"
#include "StudentProfile.h"

using namespace std;

void printCollection(vector<StudentProfile> &v);

int main()
{
  long courseNum1;
  string courseName1;
  long courseNum2;
  string courseName2;
  long courseNum3;
  string courseName3;
  unsigned long long stNo;
  unsigned long long SSN;
  string fName;
  string lName;
  int age;
  char gender;

  vector<StudentProfile> stCollection;
  fstream fin;

  fin.open("data.txt");
  if(!fin)
    cout << "File not found.";
  else
  {
    while(fin)
      {
	if(fin.eof())
	  break;
	fin >> lName >> fName >> SSN >> age >> gender >> stNo >> courseNum1 >> courseName1 >> courseNum2 >>
	  courseName2 >> courseNum3 >> courseName3;
	Course course1(courseNum1, courseName1);
	Course course2(courseNum2, courseName2);
	Course course3(courseNum3, courseName3);

	Student student(stNo, course1, course2, course3);
	Person person(SSN, fName, lName, age, gender);
	StudentProfile stProfile(person, student);
	stCollection.push_back(stProfile);
      }
  }
  printCollection(stCollection);
  return 0;
}

void printCollection(vector<StudentProfile> &v)
{
  for(int x = 0; x < v.size(); x++)
  {
    cout << "Name\t\tAge\tGender\tSSN\t\tStudent ID" << endl;
    cout << "==================================================================" << endl;
    cout << v[x].printProfile() << "\n" << endl;
  }
}
