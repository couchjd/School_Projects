#include "adjunct.h"
#include <iostream>
#include <iomanip>

AdjunctProf::AdjunctProf(){
  degree = 'X';
  noOfTA = 0;
  noOfCourses = 0;
}

AdjunctProf::AdjunctProf(string nameIn, long idIn, string emailIn, char degreeIn, int noOfTAIn, int noOfCoursesIn) : CompSciProfessor(nameIn, idIn, emailIn){
  degree = 'X';
  noOfTA = 0;
  noOfCourses = 0;
}

AdjunctProf::~AdjunctProf(){}

void AdjunctProf::print() const{
  cout << "===================================================================================================" << endl
       << setw(24) << left << "Name" << setw(10) << "ID" << setw(24) << "Email" << setw(8) << "Degree" << setw(5) << "TAs" << setw(9) << "Courses" << endl
       << "---------------------------------------------------------------------------------------------------" << endl
       << setw(24) << left << CompSciProfessor::getName() << setw(10) << CompSciProfessor::getFacultyId() << setw(24) << CompSciProfessor::getEmail() 
       << setw(8) << degree << setw(5) << noOfTA << setw(9) << noOfCourses << endl
       << "===================================================================================================" << endl;
}

float AdjunctProf::findSalary() const{
  switch(degree){
  case 'B':
    return((noOfTA*1500) + (noOfCourses*3000));
  case 'M':
    return((noOfTA*2000) + (noOfCourses*4000));
  case 'P':
    return((noOfTA*2500) + (noOfCourses*5000));
  }
}

void AdjunctProf::SetValues(string nameIn, long idIn, string emailIn, char degreeIn, int noOfTAIn, int noOfCoursesIn){
  CompSciProfessor::SetValues(nameIn, idIn, emailIn);
  setDegree(degreeIn);
  setNoOfTA(noOfTAIn);
  setNoOfCourses(noOfCoursesIn);
}
