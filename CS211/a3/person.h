#ifndef PERSON_H
#define PERSON_H

/**
 * person.h
 * Base class for modeling a person -- to be inherited from by
 * Student and Faculty classes.
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 **/
#include <string>

using namespace std;

class Person{
  friend class University;
 protected:
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;
 public:

  /**
   * Default constructor.
   **/
  Person();

  /**
   * Class constructor.
   *
   * @arg pName -- person's name.
   * @arg pEmail -- person's email address.
   * @arg pAddress -- persons's mailing address.
   * @arg pDateOfBirth -- person's date of birth.
   * @arg pGender -- person's gender.
   *
   **/
  Person(string pName, string pEmail, string pAddress, string pDateOfBirth, string pGender);
  ~Person();
};

#endif
