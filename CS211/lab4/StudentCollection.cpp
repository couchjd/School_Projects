#include "StudentCollection.h"
#include <iostream>
#include <fstream>
#include "Course.h"
#include "Student.h"
#include "Person.h"

using namespace std;

void StudentCollection::getInfo()
{
  long courseNum1, courseNum2, courseNum3;
  string courseName1, courseName2, courseName3;
  unsigned long long stNo;
  unsigned long long SSN;
  string fName;
  string lName;
  int age;
  char gender;

  fstream fin;

  fin.open("data.txt");
  if(!fin)
    cout << "File not found!";
  else
  {
    while(fin)
    {
      if(fin.eof())
	break;
      fin >> lName >> fName >> SSN >> age >> gender >> stNo >> courseNum1 >> courseName1 
	  >> courseNum2 >> courseName2 >> courseNum3 >> courseName3;
      Course course1(courseNum1, courseName1);
      Course course2(courseNum2, courseName2);
      Course course3(courseNum3, courseName3);
      Student student(stNo, course1, course2, course3);
      Person person(SSN, fName, lName, age, gender);
      StudentProfile stProfile(person, student);

      stCollection.push_back(stProfile);
    }
  }
}

void StudentCollection::printCollection()
{
  for(int x = 0; x < stCollection.size(); x++)
  {
    cout << "Name\t\tAge\tGender\tSSN\t\tStudent ID" << endl;
    cout << "==================================================================" << endl;
    cout << stCollection[x].printProfile() << "\n" << endl;
  }
}
