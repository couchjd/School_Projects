/**
 * person.cpp
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include "person.h"

Person::Person(){
  name = "";
  email = "";
  address = "";
  dateOfBirth = "";
  gender = "";
}

Person::Person(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender){
  name = fName;
  email = fEmail;
  address = fAddress;
  dateOfBirth = fDateOfBirth;
  gender = fGender;
}

Person::~Person(){
}
