/**
 * department.cpp
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (11.12.2014)
 **/
#include "department.h"

long Department::nextDepartId = 100;

Department::Department(){
  id = nextDepartId;
  name = " ";
  location = " ";
  chairId = 0;
  nextDepartId++;
}

Department::Department(string deptName, string deptLoc, long deptChairId){
  id = nextDepartId;
  name = deptName;
  location = deptLoc;
  chairId = deptChairId;
  nextDepartId++;
}

Department::~Department(){}
