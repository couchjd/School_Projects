/**
 * person.h
 * 
 * Person base class.
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (11.19.2014)
 **/

#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
  friend class Family;
 protected:
  long SSN;
  string firstName;
  string lastName;
 public:
  //Default constructor
  Person();

  //Class constructor
  //@param pSSN - SSN of Person object
  //@param fName - first name of Person
  //@param lName - last name of Person
  Person(long pSSN, string fName, string lName);
};

#endif
