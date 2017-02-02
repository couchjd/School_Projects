/**
 * university.h
 * Class for modeling a university.
 *
 * @author Jeff Couch (couch009@empress.csusm.edu)
 * @version 1.0 (11.12.2014)
 **/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "department.h"
#include "student.h"
#include "course.h"
#include "faculty.h"

using namespace std;

class University
{
protected:
  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;

  /**
   * Helper function to check if department chair exists.
   *
   * @arg long depChairId -- id to search for.
   **/
  bool chairExists(long depChairId);
 
   /**
   * Helper function to check if major exists.
   *
   * @arg string sMajor -- major to search for.
   **/
  bool majorExists(string sMajor);
  
  /**
   * Helper function to check if faculty exists.
   *
   * @arg long fFacId -- faculty id to search for.
   **/
  bool facultyExists(long fFacId);

  /**
   * Helper function to check if department exists.
   *
   * @arg long depId -- department id to search for.
   **/
  bool deptExists(long depId);
 
  /**
   * Helper function to check if student exists.
   *
   * @arg long sId -- sId to search for.
   **/
  bool studentExists(long sId);
  
  /**
   * Helper function to check if course exists.
   *
   * @arg long cId -- course id to search for.
   **/
  bool courseExists(long cId);

  static bool failure;
  static bool success;

public:

  /**
   * Default constructor. 
   **/
  University();
  
  /**
   * Default destructor.
   **/
  ~University();
  
  /**
   * Creates a new Department object and appends it to departments vector.
   *
   * @arg string depName -- name of department to be created.
   * @arg string depLoc -- location of department office.
   * @arg long depChairId -- faculty id of department chair.
   *
   * @return bool -- success if department is created.
   **/
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);

  /**
   * Removes specified Department object from departments vector.
   *
   * @arg string depId -- id of department to be removed.
   *
   * @return bool -- success if department is deleted.
   **/
  bool RemoveADepartment(long depId);  //OPTIONAL

  /**
   * Creates a new student object and appends it to students vector.
   *
   * @arg string sName -- name of student to be created.
   * @arg string sEmail -- student's email address.
   * @arg string sAddress -- student's mailing address.
   * @arg string sDateOfBirth -- student's date of birth.
   * @arg string sGender -- student's gender.
   * @arg int sYearOfStudy -- student's year of study.
   * @arg string sMajor -- student's declared major.
   * @arg long sAdvisorId -- student's advisor's id.
   *
   * @return bool -- success if student is created.
   **/
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, 
			int sYearOfStudy, string sMajor, long sAdvisorId);

  /**
   * Removes a student object from students vector.
   *
   * @arg long sStId -- id of student to be removed.
   *
   * @return bool -- success if student is removed.
   **/
  bool RemoveAStudent(long sStId);  //OPTIONAL

  /**
   * Creates a new Course object and appends it to courses vector.
   *
   * @arg string cName -- name of course to be created.
   * @arg long cDepId -- course's department.
   * @arg long depChairId -- faculty id of department chair.
   *
   * @return bool -- success if department is created.
   **/
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);

  /**
   * Removes a course from courses vector.
   *
   * @arg string depName -- name of department to be created.
   * @arg string depLoc -- location of department office.
   * @arg long depChairId -- faculty id of department chair.
   *
   * @return bool -- success if department is created.
   **/
  bool RemoveACourse(long cCRN);  //OPTIONAL

  /**
   * Creates a new faculty object and appends it to faculties vector.
   *
   * @arg string fName -- name of faculty to be created.
   * @arg string fEmail -- faculty's email address.
   * @arg string fAddress -- faculty's mailing address.
   * @arg string fDateOfBirth -- faculty's date of birth.
   * @arg string fGender -- faculty's gender.
   * @arg float fSalary -- faculty's salary.
   * @arg int fYearOfExp -- faculty's years of experience.
   * @arg long fDepId -- faculty's department id.
   *
   * @return bool -- success if faculty is created.
   **/
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
			float fSalary, int fYearOfExp, long fDepId);

  /**
   * Remove a faculty object from faculties vector..
   *
   * @arg long fFactId -- id of faculty to remove.
   *
   * @return bool -- success if faculty is removed.
   **/
  bool RemoveAFaculty(long fFactId);  //OPTIONAL

  /**
   * Prints a list of courses taught by the specified faculty.
   *
   * @arg long facultyId -- faculty id to print courses for.
   *
   * @return bool -- success if faculty id is found.
   **/
  bool ListCoursesTaughtByFaculty(long facultyId);

  /**
   * Prints a list of courses taken by the specified student.
   *
   * @arg long studentId -- student id to print courses for.
   *
   * @return bool -- success if student id is found.
   **/
  bool ListCoursesTakenByStudent(long studentId);

  /**
   * Prints a list of faculty member in specified department.
   *
   * @arg long departId -- department id to print faculty members for.
   *
   * @return bool -- success if department id is found.
   **/
  bool ListFacultiesInDepartment (long departId);

  /**
   * Prints a list of students of specified faculty member.
   *
   * @arg long facultyId -- faculty id to print students for.
   *
   * @return bool -- success if faculty id is found.
   **/
  bool ListStudentsOfAFaculty(long facultyId);

  /**
   * Prints a list of courses in specified department.
   *
   * @arg long departId -- department id to print courses for.
   *
   * @return bool -- success if department id is found.
   **/
  bool ListCoursesOfADepartment(long departId);

  /**
   * Adds a new Course object to the courses vector of specified student.
   *
   * @arg long courseId -- course id of course to be created.
   * @arg long stId -- student id of student to add course for.
   *
   * @return bool -- success if course is added.
   **/
  bool AddACourseForAStudent(long courseId, long stId);

  /**
   * Removes a Course object from the courses vector of specified student.
   *
   * @arg long courseId -- course id of course to be removed.
   * @arg long stId -- student id of student to remove course from.
   *
   * @return bool -- success if course is removed.
   **/
  bool DropACourseForAStudent(long courseId, long stId);

  /**
   * Assigns specified faculty as chair of specified department.
   *
   * @arg long facultyId -- faculty id to assign as chair of department.
   * @arg long departId -- department to assign chair for.
   *
   * @return bool -- success if chair is assigned.
   **/
  bool AssignDepartmentChair(long facultyId, long departId);

  /**
   * Assigns specified faculty as instructor of specified course..
   *
   * @arg long facultyId -- faculty id to assign course to.
   * @arg long courseId -- course to assign instructor to.
   *
   * @return bool -- success if instructor is assigned successfully.
   **/
  bool AssignInstructorToCourse (long facultyId, long courseId);
  
  /**
   * Prints a list of departments.
   *
   * @return bool -- success if department list is printed.
   **/
  bool ListDepartments();

  /**
   * Prints a list of students.
   *
   * @return bool -- success if student list is printed.
   **/
  bool ListStudents();

  /**
   * Prints a list of courses.
   *
   * @return bool -- success if course list is printed.
   **/
  bool ListCourses();

  /**
   * Prints a list of faculty.
   *
   * @return bool -- success if faculty list is printed.
   **/
  bool ListFaculties();
    
  /**
   * Processes contents of transaction file and calls appropriate methods.
   *
   * @return bool -- success if transaction file is processed successfully..
   **/
  bool ProcessTransactionFile(string fileName);
};
