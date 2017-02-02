#include "Person.h"
#include <sstream>

Person::Person(){};
Person::Person(long SSNin, string fNameIn, string lNameIn, int ageIn, char genderIn)
{
  setSSN(SSNin);
  setFName(fNameIn);
  setLName(lNameIn);
  setAge(ageIn);
  setGender(genderIn);
}
Person::~Person(){};

void Person::setSSN(long SSNin) {SSN = SSNin;}
void Person::setFName(string fNameIn) {fName = fNameIn;}
void Person::setLName(string lNameIn) {lName = lNameIn;}
void Person::setAge(int ageIn) {age = ageIn;}
void Person::setGender(char genderIn) {gender = genderIn;}

string Person::printInfo() 
{
  stringstream retString;
  retString << lName << ", " << fName << "\t" << age << "\t" << gender << "\t" << SSN;
  return retString.str();
}
long Person::getSSN() {return SSN;}
string Person::getFName() {return fName;}
string Person::getLName() {return lName;}
int Person::getAge() {return age;}
char Person::getGender() {return gender;}
