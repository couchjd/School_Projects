/**
 * wife.h
 *
 *
 *
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version 1.0 (11.19.2014)
 **/

#ifndef WIFE_H
#define WIFE_H

#include <string>
#include "person.h"
#include "child.h"

using namespace std;

class Wife : public Person{
  friend class Family;
 protected:
  //pointer to first child in list of children.
  Child* myChildren;  

 public:
  //Default constructor
  Wife();
  
  //Class constructor
  //@param wSSN - SSN of Wife object.
  //@param fName - first name of Wife.
  //@param lName - last name of Wife.
  Wife(long wSSN, string fName, string lName);
};

#endif
