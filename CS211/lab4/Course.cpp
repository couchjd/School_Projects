#include "Course.h"
#include <sstream>

Course::Course(){}
Course::Course(long courseNumIn, string courseNameIn)
{
  setCourseNum(courseNumIn);
  setCourseName(courseNameIn);
}
Course::~Course(){}

void Course::setCourseNum(long courseNumIn) {courseNum = courseNumIn;}
void Course::setCourseName(string courseNameIn) {courseName = courseNameIn;}

string Course::printInfo()
{
  stringstream retStream;
  retStream << "\t" << courseNum << "\t\t" << courseName;
  return retStream.str();
}
long Course::getCourseNum(){return courseNum;}
string Course::getCourseName(){return courseName;}
