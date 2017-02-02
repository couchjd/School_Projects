#include "StudentProfile.h"

StudentProfile::StudentProfile(){}
StudentProfile::StudentProfile(Person personalInfoIn, Student stdInfoIn)
{
  setPersonalInfo(personalInfoIn);
  setStdInfo(stdInfoIn);
}

StudentProfile::~StudentProfile(){}


string StudentProfile::printProfile()
{
  return(personalInfo.printInfo() + " " + stdInfo.printInfo());
}
void StudentProfile::setPersonalInfo(Person personalInfoIn) {personalInfo = personalInfoIn;}
void StudentProfile::setStdInfo(Student stdInfoIn) {stdInfo = stdInfoIn;}

Person StudentProfile::getPersonalInfo() {return personalInfo;}
Student StudentProfile::getStdInfo() {return stdInfo;}
