/**
 * Employee.cpp
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (09.18.2014)
 **/
#include "Employee.h"
#include <iomanip>

int Employee::totalNumOfEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;

Employee::Employee() : officeNo(nextOfficeNo++), empId(nextEmpId++)
{
  name = "Unknown";
  deptNo = 0;
  empPosition = 'E';
  yearOfExp = 0;
  salary = 0;

  totalNumOfEmployees++;
}

Employee::~Employee()
{
  totalNumOfEmployees--;
}

Employee::Employee(string nameIn, int deptNoIn, char empPositionIn, int yearOfExpIn) : officeNo(nextOfficeNo), empId(nextEmpId)
{
  name = nameIn;
  deptNo = deptNoIn;
  empPosition = empPositionIn;
  yearOfExp = yearOfExpIn;
  salary = 0;

  totalNumOfEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

void Employee::print() const
{
  cout << "\n=====================================================================================\n"
       << "Employee Record\t\t\tTotal Employees: " << totalNumOfEmployees << endl
       << "-------------------------------------------------------------------------------------\n"
       << setw(8) << left
       << "ID" << setw(16) << "Name" << setw(8) << "Dept" << setw(12) << "Position" 
       << setw(16) << "Experience" << setw(8) << "Salary" << endl
       << "=====================================================================================\n";

  cout << setw(8) << left
       << empId  << setw(16) << name << setw(8) << deptNo << setw(12) 
       << empPosition << setw(16) << yearOfExp << setw(8) << salary << endl << endl;
}

void Employee::getInfo()
{
  cout << "Enter name: ";
  getline(cin, name);
  cout << "Enter position: ";
  cin >> empPosition;
  cout << "Enter years of experience: ";
  cin >> yearOfExp;
}
