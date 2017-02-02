#ifndef DEPARTMENT_H
#define DEPARTMENT_H
/**
 * department.h
 * A class for modeling a university department.
 * 
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.28.2014)
 *
 **/
#include <string>

using namespace std;

class Department{
  friend class University;
 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId;
 public:

  /**
   * Default constructor.
   **/
  Department();

  /**
   *Class constructor.
   *
   * @arg deptName -- name of department to be created
   * @arg deptLoc -- location of department.
   * @arg deptChairId -- faculty id of department chair.
   **/
  Department(string deptName, string deptLoc, long deptChairId);
  ~Department();
};

#endif
