#ifndef TENURE_H
#define TENURE_H

#include <string>
#include <vector>
#include "professor.h"

class TenureTrackProf : CompSciProfessor{
 public:
  TenureTrackProf();
  TenureTrackProf(string nameIn, long idIn, string emailIn, char rankIn, int yearOfExpIn);
  ~TenureTrackProf();

  string getName(){return CompSciProfessor::getName();}
  long getFacultyId(){return CompSciProfessor::getFacultyId();}
  string getEmail(){return CompSciProfessor::getEmail();}
  char getRank(){return rank;}
  int getYearOfExp(){return yearOfExp;}

  void setName(string nameIn){CompSciProfessor::setName(nameIn);}
  void setFacultyId(long idIn){CompSciProfessor::setFacultyId(idIn);}
  void setEmail(string emailIn){CompSciProfessor::setEmail(emailIn);}
  void setRank(char rankIn){rank = rankIn;}
  void setYearOfExp(int yearOfExpIn){yearOfExp = yearOfExpIn;}
  void SetValues(string nameIn, long idIn, string emailIn, char rankIn, int yearOfExpIn);

  void print() const;
  float findSalary() const;

 protected:
  char rank;
  int yearOfExp;
};

#endif
