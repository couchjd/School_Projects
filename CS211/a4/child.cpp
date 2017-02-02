/**
 * child.cpp
 *
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version 1.0 (11.19.2014)
 **/

#include "child.h"

Child::Child(){
}

Child::Child(long cSSN, string fName, string lName) : Person(cSSN, fName, lName){
  mySibling = NULL;
}
