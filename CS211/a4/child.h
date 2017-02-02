/**
 * child.h
 * Child class
 *
 *
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version 1.0 (11.19.2014)
 **/

#ifndef CHILD_H
#define CHILD_H

#include "person.h"
#include <string>

using namespace std;

class Child : public Person{
  friend class Family;
 protected:
  /**
   * Pointer to sibling of child object.
   **/
  Child* mySibling;  

 public:
  /**
   * Default constructor.
   */
  Child();

  /**
   * Class constructor.
   *
   * @param cSSN - SSN of child
   * @param fName - first name of child
   * @param lName - last name of child
   *
   **/
  Child(long cSSN, string fName, string lName);
};

#endif
