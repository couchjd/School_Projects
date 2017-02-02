/**
 * husband.h
 *
 *
 *
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version 1.0 (11.19.2014)
 **/

#ifndef HUSBAND_H
#define HUSBAND_H

#include <string>
#include "person.h"
#include "wife.h"

using namespace std;

class Husband : public Person{
  friend class Family;
 protected:
  //Pointer to Wife of Husband object.
  Wife* myWife;
  //Pointer to next Husband object.
  Husband* nextFamily;

 public:
  //Default constructor.
  Husband();

  //Class constructor.
  //@param hSSN - SSN of husband
  //@param fName - first name of husband
  //@param lName - last name of husband
  Husband(long hSSN, string fName, string lName);
};

#endif
