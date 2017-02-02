/**
 * wife.cpp
 *
 *
 *
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version 1.0 (11.19.2014)
 **/

#include "wife.h"

Wife::Wife(){
}

Wife::Wife(long wSSN, string fName, string lName) : Person(wSSN, fName, lName){
  myChildren = NULL;
}
