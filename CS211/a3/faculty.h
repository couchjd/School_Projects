#ifndef FACULTY_H
#define FACULTY_H

/**
 * faculty.h
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include <string>
#include "person.h"

using namespace std;

class Faculty : public Person {
  friend class University;
 protected:
  long id;
  float salary;
  int yearOfExp;
  int departId;
  static long nextFacId;
 public:

  /**
   * Default constructor.
   **/
  Faculty();

  /**
   * Class constructor.
   *
   * @arg fName -- name of faculty.
   * @arg fEmail -- email of faculty.
   * @arg fAddress -- address of faculty.
   * @arg fDateOfBirth -- date of birth of faculty.
   * @arg fGender -- gender of faculty.
   * @arg fSalary -- salary of faculty.
   * @arg fYearOfExp -- faculty's years of experience.
   * @arg fDepId -- faculty's department id.
   *
   **/
  Faculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
	  float fSalary, int fYearOfExp, long fDepId);
  ~Faculty();
};

#endif
