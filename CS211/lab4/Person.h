#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
private:
  long SSN;
  string fName;
  string lName;
  int age;
  char gender;

public:
  Person();
  Person(long SSNin, string fNameIn, string lNameIn, int ageIn, char genderIn);
  ~Person();

  void setSSN(long SSNin);
  void setFName(string fNameIn);
  void setLName(string lNameIn);
  void setAge(int ageIn);
  void setGender(char genderIn);

  string printInfo();
  long getSSN();
  string getFName();
  string getLName();
  int getAge();
  char getGender();
};

#endif
