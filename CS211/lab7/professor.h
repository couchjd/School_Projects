#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>

using namespace std;

class CompSciProfessor{
 protected:
  string name;
  long facultyId;
  string email;

 public:
  CompSciProfessor();
  CompSciProfessor(string nameIn, long idIn, string emailIn);
  ~CompSciProfessor();

  string getName() const {return name;} 
  long getFacultyId() const {return facultyId;}
  string getEmail() const {return email;}

  void setName(string &nameIn){name = nameIn;}
  void setFacultyId(long idIn){facultyId = idIn;}
  void setEmail(string emailIn){email = emailIn;}
  void SetValues(string nameIn, long idIn, string emailIn);
};

#endif
