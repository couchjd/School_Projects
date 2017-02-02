/**
 * faculty.cpp
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include "faculty.h"

long Faculty::nextFacId = 600;

Faculty::Faculty(){
  id = nextFacId;
  salary = 0;
  yearOfExp = 0;
  departId = 0;
  nextFacId++;
}

Faculty::Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
		 float fSalary, int fYearOfExp, long fDepId) : Person(fName, fEmail, fAddress, fDateOfBirth, fGender){
  id = nextFacId;
  salary = fSalary;
  yearOfExp = fYearOfExp;
  departId = fDepId;
  nextFacId++;
}

Faculty::~Faculty(){
}
