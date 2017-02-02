/**
 * Employee.h
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (09.18.2014)
 **/

#include <string>
#include <iostream>

using namespace std;

class Employee
{
 public:
  Employee();
  ~Employee();
  Employee(string nameIn, int deptNoIn, char empPositionIn, int yearOfExpIn);
  void print() const;
  void getInfo();
  friend void setSalary(Employee &empIn);

 private:
  string name;
  const long officeNo;
  const long empId;
  int deptNo ;
  char empPosition;
  int yearOfExp;
  float salary;
  static int totalNumOfEmployees;
  static int nextEmpId;
  static int nextOfficeNo;
};
