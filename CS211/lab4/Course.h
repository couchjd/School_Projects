#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
private:
  long courseNum;
  string courseName;

public:
  Course();
  Course(long courseNumIn, string courseNameIn);
  ~Course();

  void setCourseNum(long courseNumIn);
  void setCourseName(string courseNameIn);

  string printInfo();
  long getCourseNum();
  string getCourseName();
};

#endif
