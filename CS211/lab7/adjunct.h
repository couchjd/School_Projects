#ifndef ADJUNCT_H
#define ADJUNCT_H

#include <string>
#include <vector>
#include "professor.h"

using namespace std;

class AdjunctProf : public CompSciProfessor{
 protected:
  char degree;
  int noOfTA;
  int noOfCourses;

 public:
  AdjunctProf();
  AdjunctProf(string nameIn, long idIn, string emailIn, char degreeIn, int noOfTAIn, int noOfCoursesIn);
  ~AdjunctProf();
  
  string getName(){return CompSciProfessor::getName();}
  long getFacultyId(){return CompSciProfessor::getFacultyId();}
  string getEmail(){return CompSciProfessor::getEmail();}
  char getDegree(){return degree;}
  int getNoOfTA(){return noOfTA;}
  int getNoOfCourses(){return noOfCourses;}

  //  void setName(string nameIn){CompSciProfessor::setName(nameIn);}
  //void setFacultyId(long idIn){CompSciProfessor::setFacultyId(idIn);}
  //void setEmail(string emailIn){CompSciProfessor::setEmail(emailIn);}
  void setDegree(char degreeIn){degree = degreeIn;}
  void setNoOfTA(int noOfTAIn){noOfTA = noOfTAIn;}
  void setNoOfCourses(int noOfCoursesIn){noOfCourses = noOfCoursesIn;}
  void SetValues(string nameIn, long idIn, string emailIn, char degreeIn, int noOfTAIn, int noOfCoursesIn);

  void print() const;
  float findSalary() const;
};

#endif
