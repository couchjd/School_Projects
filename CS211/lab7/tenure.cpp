#include "tenure.h"
#include <iostream>
#include <iomanip>

TenureTrackProf::TenureTrackProf() : CompSciProfessor(){
  rank = 'X';
  yearOfExp = 0;
}

TenureTrackProf::TenureTrackProf(string nameIn, long idIn, string emailIn, char rankIn, int yearOfExpIn) : CompSciProfessor(nameIn, idIn, emailIn){
  rank = rankIn;
  yearOfExp = yearOfExpIn;
}
TenureTrackProf::~TenureTrackProf(){}

void TenureTrackProf::print() const{
  cout << "===================================================================================================" << endl
       << setw(24) << left << "Name" << setw(10) << "ID" << setw(24) << "Email" << setw(6) << "Rank" << setw(7) << "Years" << endl
       << "---------------------------------------------------------------------------------------------------" << endl
       << setw(24) << left << CompSciProfessor::getName() << setw(10) << CompSciProfessor::getFacultyId() << setw(24) << CompSciProfessor::getEmail() 
       << setw(6) << rank << setw(7) << yearOfExp << endl
       << "===================================================================================================" << endl;
}

float TenureTrackProf::findSalary() const{
  switch(rank){
  case 'A':
    return(65000 + (yearOfExp*1500));
  case 'S':
    return(80000 + (yearOfExp*1500));
  case 'F':
    return(90000 + (yearOfExp*1500));
  }
}

void TenureTrackProf::SetValues(string nameIn, long idIn, string emailIn, char rankIn, int yearOfExpIn){
  CompSciProfessor::SetValues(nameIn, idIn, emailIn);
  setRank(rankIn);
  setYearOfExp(yearOfExpIn);
}
