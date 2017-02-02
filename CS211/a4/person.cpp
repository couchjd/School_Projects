#include "person.h"

using namespace std;

Person::Person(){
  SSN = 0;
  firstName = "";
  lastName = "";
}

Person::Person(long pSSN, string fName, string lName){
  SSN = pSSN;
  firstName = fName;
  lastName = lName;
}
