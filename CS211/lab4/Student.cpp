#include "Student.h"
#include <sstream>

Student::Student(){};
Student::Student(long stNoIn, Course course1In, Course course2In, Course course3In)
{
  setStNo(stNoIn);
  setCourse1(course1In);
  setCourse2(course2In);
  setCourse3(course3In);
}
Student::~Student(){};

void Student::setStNo(long stNoIn) {stNo = stNoIn;}
void Student::setCourse1(Course course1In) {course1 = course1In;}
void Student::setCourse2(Course course2In) {course2 = course2In;}
void Student::setCourse3(Course course3In) {course3 = course3In;}

string Student::printInfo()
{
  stringstream retString;
  retString << "\t" << stNo << "\n==================================================================\n"
	    << "Enrolled Courses" << "\tCourse #\tCourse Name" 
	    <<  "\n==================================================================\n\t\t"
	    << course1.printInfo() << "\n\t\t" << course2.printInfo() << "\n\t\t" << course3.printInfo();
  return retString.str();
}

long Student::getStNo() {return stNo;}
Course Student::getCourse1() {return course1;}
Course Student::getCourse2() {return course2;}
Course Student::getCourse3() {return course3;}
