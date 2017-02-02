/**
 * student.cpp
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include "student.h"

long Student::nextStId = 500;

Student::Student() : Person(){
  id = nextStId;
  yearOfStudy = 0;
  major = "none";
  advisorId = 0;
  nextStId++;
}

Student::Student(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, 
		 int sYearOfStudy, string sMajor, long sAdvisorId) : Person(sName, sEmail, sAddress, sDateOfBirth, sGender){
  id = nextStId;
  yearOfStudy = sYearOfStudy;
  major = sMajor;
  advisorId = sAdvisorId;
  nextStId++;
}

Student::~Student(){
}
