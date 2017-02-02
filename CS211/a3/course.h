/**
 * course.h
 * A class for modeling a university course.
 *
 * @author Jeff Couch (couch009@empress.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course{
  friend class University;
 private:
  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;
 public:
  /**
   * Default constructor.
   **/
  Course();
  
  /**
   * Constructor.
   *
   * @arg cName -- name of course.
   * @arg cDepId -- department id of course.
   * @arg cTaughtBy -- faculty id of course instructor.
   * @arg cMaxSeat -- total number of seats available in course.
   **/
  Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  
  /**
   * Default destructor.
   **/
  ~Course();
};

#endif
