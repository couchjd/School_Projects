/**
 * husband.cpp
 *
 *
 *
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version 1.0 (11.19.2014)
 **/

#include "husband.h"

Husband::Husband(){
}

Husband::Husband(long hSSN, string fName, string lName) : Person(hSSN, fName, lName){
  nextFamily = NULL;
  myWife = NULL;
}
