#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Course
{
public:
  long courseNum;
  string courseName;
};

class Person
{
public:
  long SSN;
  string fName;
  string lName;
  int age;
  char gender;
};

class Student
{
public:
  long stNo;
  Course course1;
  Course course2;
  Course course3;
};

class StudentProfile
{
public:
  Person personalInfo;
  Student stdInfo;
};

void printCollection(const vector<StudentProfile> &v);
void getInfo(vector<StudentProfile> &p);

int main()
{
  vector<StudentProfile> stCollection;

  getInfo(stCollection);
  printCollection(stCollection);

  return 0;
}

void getInfo(vector<StudentProfile> &p)
{
  StudentProfile new_student;
  ifstream fin;
  fin.open("data.txt");
  fin >> new_student.personalInfo.lName >> new_student.personalInfo.fName >> new_student.personalInfo.SSN >>
    new_student.personalInfo.age >> new_student.personalInfo.gender >> new_student.stdInfo.stNo >>
    new_student.stdInfo.course1.courseNum >> new_student.stdInfo.course1.courseName >>
    new_student.stdInfo.course2.courseNum >> new_student.stdInfo.course2.courseName >>
    new_student.stdInfo.course3.courseNum >> new_student.stdInfo.course3.courseName;
  while(fin)
  {
    p.push_back(new_student);
    fin >> new_student.personalInfo.lName >> new_student.personalInfo.fName >> new_student.personalInfo.SSN >>
      new_student.personalInfo.age >> new_student.personalInfo.gender >> new_student.stdInfo.stNo >>
      new_student.stdInfo.course1.courseNum >> new_student.stdInfo.course1.courseName >>
      new_student.stdInfo.course2.courseNum >> new_student.stdInfo.course2.courseName >>
      new_student.stdInfo.course3.courseNum >> new_student.stdInfo.course3.courseName;
  }
}

void printCollection(const vector<StudentProfile> &v)
{
  for(int x = 0; x < v.size(); x++)
  {
    cout << "Name\t\tAge\tGender\tSSN\t\tStudent ID" << endl;
    cout << "==================================================================" << endl;
    cout << v[x].personalInfo.lName << ", " << v[x].personalInfo.fName << "\t" << v[x].personalInfo.age <<
      "\t" << v[x].personalInfo.gender << "\t" << v[x].personalInfo.SSN << "\t" << v[x].stdInfo.stNo << endl;
    cout << "==================================================================" << endl;
    cout << "Enrolled Courses:\t\tCourse ID\tCourse Name" << endl;
    cout << "==================================================================" << endl;
    cout << "\t\t\t\t" << v[x].stdInfo.course1.courseNum << "\t\t" << v[x].stdInfo.course1.courseName << endl;
    cout << "\t\t\t\t" << v[x].stdInfo.course2.courseNum << "\t\t" << v[x].stdInfo.course2.courseName << endl;
    cout << "\t\t\t\t" << v[x].stdInfo.course3.courseNum << "\t\t" << v[x].stdInfo.course3.courseName << endl << endl;
  }
}
