#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Course.h"

using namespace std;

class Student
{
private:
  long stNo;
  Course course1;
  Course course2;
  Course course3;

public:
  Student();
  Student(long stNoIn, Course course1In, Course course2In, Course course3In);
  ~Student();

  void setStNo(long stNoIn);
  void setCourse1(Course course1In);
  void setCourse2(Course course2In);
  void setCourse3(Course course3In);

  string printInfo();
  long getStNo();
  Course getCourse1();
  Course getCourse2();
  Course getCourse3();
};

#endif
