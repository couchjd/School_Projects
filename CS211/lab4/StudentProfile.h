#include <string>
#include "Person.h"
#include "Student.h"

using namespace std;

class StudentProfile
{
private:
  Person personalInfo;
  Student stdInfo;

public:
  StudentProfile();
  StudentProfile(Person personalInfoIn, Student stdInfoIn);
  ~StudentProfile();

  string printProfile();
  void setPersonalInfo(Person personalInfoIn);
  void setStdInfo(Student stdInfoIn);

  Person getPersonalInfo();
  Student getStdInfo();
};
