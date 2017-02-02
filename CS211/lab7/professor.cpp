#include "professor.h"
#include <iostream>
#include <iomanip>

CompSciProfessor::CompSciProfessor(){
  name = "unknown";
  facultyId = 000000000;
  email = "none@domain.net";
}

CompSciProfessor::CompSciProfessor(string nameIn, long idIn, string emailIn){
  name = nameIn;
  facultyId = idIn;
  email = emailIn;
}

CompSciProfessor::~CompSciProfessor(){}

void CompSciProfessor::SetValues(string nameIn, long idIn, string emailIn){
  setName(nameIn);
  setFacultyId(idIn);
  setEmail(emailIn);
}
