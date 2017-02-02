/**
 * course.cpp
 *
 * @author Jeff Couch (couch009@empress.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include "course.h"

long Course::nextCRN = 200;

Course::Course(){
  CRN = nextCRN;
  maxAvailableSeats = 0;
  name = "unknown";
  departId = 0;
  assignedSeats = 0;
  isTaughtBy = 0;
  nextCRN++;
}

Course::Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat){
  CRN = nextCRN;
  maxAvailableSeats = cMaxSeat;
  name = cName;
  departId = cDepId;
  assignedSeats = 0;
  isTaughtBy = cTaughtBy;
  nextCRN++;
}

Course::~Course(){
}
