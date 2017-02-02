#ifndef STUDENT_H
#define STUDENT_H
/**
 * student.h
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include "course.h"
#include "person.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Student : public Person{
  friend class University;
 protected:
  long id;
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;
 public:
  Student();
  Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, 
	  int sYearOfStudy, string sMajor, long sAdvisorId);
  ~Student();
};

#endif
