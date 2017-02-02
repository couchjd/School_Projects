/**
 * university.cpp
 * Class for modeling a university.
 *
 * @author Jeff Couch (couch009@empress.csusm.edu)
 * @version 1.0 (11.12.2014)
 **/

#include "university.h"

bool University::failure = false;
bool University::success = true;

//----------------------------------------------------------------------------
University::University()
{

}
//----------------------------------------------------------------------------

University::~University()
{

}
//----------------------------------------------------------------------------

bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  if(depChairId != 0 && !chairExists(depChairId)){
    cout << "\nCould not create department!  Department chair id [" << depChairId << "] is unknown.\n" << endl;
    return failure;
  }
  
  Department newDept(depName, depLoc, depChairId);
  Departments.push_back(newDept);

  return success;
}
//----------------------------------------------------------------------------

bool University::RemoveADepartment(long depId)
{
}

//----------------------------------------------------------------------------

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,
								  int sYearOfStudy, string sMajor, long sAdvisorId)
{
  //check if major and advisor exist
  if(sMajor != "" && !majorExists(sMajor)){
    cout << "\nCould not create student!  Major [" << sMajor << "] is unknown.\n" << endl;
    return failure;
  }
  if(sAdvisorId == 0 && !facultyExists(sAdvisorId)){
    cout << "\nCould not create student!  Advisor [" << sAdvisorId << "] is unknown.\n" << endl;
    return failure;
  }

  Student newStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
  Students.push_back(newStudent);
  
  return success;
}
//----------------------------------------------------------------------------

bool University::RemoveAStudent(long sStId)
{
}
//----------------------------------------------------------------------------

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  //check if faculty and department exist.
  if(cTaughtBy != 0 && !facultyExists(cTaughtBy)){
    cout << "\nCould not create course!  Faculty [" << cTaughtBy << "] is unknown.\n" << endl;
    return failure;
  }
  if(!deptExists(cDepId)){
    cout << "\nCould not create course!  Department [" << cDepId << "] is unknown.\n" << endl;
    return failure;
  }

  Course newCourse(cName, cDepId, cTaughtBy, cMaxSeat);
  Courses.push_back(newCourse);
  
  return success;
}
//----------------------------------------------------------------------------

bool University::RemoveACourse(long cCRN)
{
/*
  - check if the cCRN passed to this method is a valid existing course id. If not
  return failure; otherwise,
  - search and remove the course from the Courses vector only if no student is currently taking 
  this course 
  - return success
*/
}
//----------------------------------------------------------------------------

bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,
								  float fSalary, int fYearOfExp, long fDepId)
{
  //check if department exists.
  if(!deptExists(fDepId)){
    cout << "Could not create faculty!  Department [" << fDepId << "] is unknown." << endl;
    return failure;
  }

  Faculty newFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
  Faculties.push_back(newFaculty);
  
  return success;
}
//----------------------------------------------------------------------------

bool University::RemoveAFaculty(long fFactId)
{
/*
  - check if the fFactId passed to this method is a valid existing faculty id. If not
  return failure; otherwise,
  - search and remove the faculty from the Faculties vector only if this faculty is not 
  teaching a course nor advising any student, nor chairing any department
  - return success
*/
}
//----------------------------------------------------------------------------

bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  cout << endl;
  //check if faculty exists.
  if(facultyId == 0 || !facultyExists(facultyId)){
    cout << "\nCould not list courses for faculyt!  No courses available for faculty [" << facultyId << "]." << endl;
    return failure;
  }
  for(int x = 0; x < Courses.size(); x++){
    if(Courses[x].isTaughtBy == facultyId)
      cout << Courses[x].CRN << "\t" << Courses[x].name << endl;
  }
  cout << endl;
  return success;
}
//----------------------------------------------------------------------------

bool University::ListCoursesTakenByStudent(long studentId)
{
  cout << endl;
  //check if student exists.
  if(studentId == 0 || !studentExists(studentId)){
    cout << "\nStudent [" << studentId << "] not found." << endl;
    return failure;
  }
  for(int x = 0; x < Students.size(); x++){
    if(Students[x].id == studentId){
      for(int y = 0; y < Students[x].coursesTaken.size(); y++){
	cout << Students[x].coursesTaken[y].CRN << "\t"
	     << Students[x].coursesTaken[y].name << endl;
      }
    }
  }
  cout << endl;
  return success;
}
//----------------------------------------------------------------------------

bool University::ListFacultiesInDepartment (long departId)
{
  cout << endl;
  //check if department exists.
  if(!deptExists(departId)){
    cout << "\nCould not list faculty!  Department [" << departId << "] not found." << endl;
    return failure;
  }
  for(int x = 0; x < Faculties.size(); x++){
    if(Faculties[x].departId == departId)
      cout << Faculties[x].id << "\t" << Faculties[x].name << endl;
  }
  cout << endl;
  return success;
}
//----------------------------------------------------------------------------

bool University::ListStudentsOfAFaculty(long facultyId)
{
  cout << endl;
  //check if faculty exists.
  if(!facultyExists(facultyId)){
    cout << "\nCould not list students!  Faculty [" << facultyId << "] not found." << endl;
    return failure;
  }
  //check the courses of each student for facultyId.
  for(int x = 0; x < Students.size(); x++){
    for(int y = 0; y < Students[x].coursesTaken.size(); y++){
      if(Students[x].coursesTaken[y].isTaughtBy == facultyId){
	cout << Students[x].id << "\t" << Students[x].name << endl;
      }
    }
  }
  cout << endl;
  return success;
}
//----------------------------------------------------------------------------

bool University::ListCoursesOfADepartment(long departId)
{
  cout << endl;
  //check if department exists.
  if(!deptExists(departId)){
    cout << "\nCould not list courses!  Department [" << departId << "] not found." << endl;
    return failure;
  }
  for(int x = 0; x < Courses.size(); x++){
    if(Courses[x].departId == departId){
      cout << Courses[x].CRN << "\t" <<  Courses[x].name << endl;
    }
  }
  cout << endl;
  return success;
}
//----------------------------------------------------------------------------

bool University::AddACourseForAStudent(long courseId, long stId)
{
  //check if course and student exist.
  if(!courseExists(courseId)){
    cout << "\nCould not add course for student!  Course [" << courseId << "] not found." << endl;
    return failure;
  }
  if(!studentExists(stId)){
    cout << "\nCould not add course for student!  Student [" << stId << "] not found." << endl;
    return failure;
  }
  cout << endl;
  //check through list of all courses.
  for(int x = 0; x < Courses.size(); x++){
    if(Courses[x].CRN == courseId){
      //check if course is full.
      if(Courses[x].assignedSeats < Courses[x].maxAvailableSeats){
	for(int y = 0; y < Students.size(); y++){
	  if(Students[y].id == stId){
	    Students[y].coursesTaken.push_back(Courses[x]);
	  }
	  Courses[x].assignedSeats++;
	  return success;
	}
      }
    }
  }
}
//----------------------------------------------------------------------------

bool University::DropACourseForAStudent(long courseId, long stId)
{
  //check if course and student exist.
  if(!courseExists(courseId)){
    cout << "\nCould not drop course for student!  Course [" << courseId << "] not found." << endl;
    return failure;
  }
  if(!studentExists(stId)){
    cout << "\nCould not drop course for student!  Student [" << stId << "] not found." << endl;
    return failure;
  }
  //check through list of all students.
  for(int x = 0; x < Students.size(); x++){
    if(Students[x].id == stId){
      //check each student's list of courses.
      for(int y = 0; y < Students[x].coursesTaken.size(); y++){
	if(Students[x].coursesTaken[y].CRN == courseId){
	  Students[x].coursesTaken.erase(Students[x].coursesTaken.begin() + y);
	  for(int z = 0; z < Courses.size(); z++){
	    if(Courses[z].CRN == courseId)
	      Courses[z].assignedSeats--;
	  }
	}
      }
    }
  }
  return success;
}
//----------------------------------------------------------------------------

bool University::AssignDepartmentChair(long facultyId, long departId)
{
  //check if facutly and department exist
  if(!facultyExists(facultyId)){
    cout << "\nCould not assign department chair!  Faculty [" << facultyId << "] not found." << endl;
    return failure;
  }
  if(!deptExists(departId)){
    cout << "\nCould not assign department chair!  Department [" << departId << "] not found." << endl;
    return failure;
  }
  for(int x = 0; x < Departments.size(); x++){
    if(Departments[x].id == departId){
      Departments[x].chairId = facultyId;
    }
  }
  return success;
}
//----------------------------------------------------------------------------

bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  //check if faculty and course exist.
  if(!facultyExists(facultyId)){
    cout << "\nCould not assign instructor to course!  Faculty [" << facultyId << "] not found." << endl;
    return failure;
  }
  if(!courseExists(courseId)){
    cout << "\nCould not assign instructor to course!  Course [" << courseId << "] not found." << endl;
    return failure;
  }
  for(int x = 0; x < Courses.size(); x++){
    if(Courses[x].CRN == courseId){
      Courses[x].isTaughtBy = facultyId;
    }
  }
}
//----------------------------------------------------------------------------
bool University::ListDepartments()
{
  for(int x = 0; x < Departments.size(); x++){
    cout << Departments[x].id << "\t" << Departments[x].name << endl;
  }
  cout << endl;
}
//----------------------------------------------------------------------------

bool University::ListStudents()
{
  for(int x = 0; x < Students.size(); x++){
    cout << Students[x].id << "\t" << Students[x].name <<  endl;
  }
  cout << endl;
}
//----------------------------------------------------------------------------

bool University::ListCourses()
{
  for(int x = 0; x < Courses.size(); x++){
    cout << Courses[x].CRN << "\t" << Courses[x].name << endl;
  }
  cout << endl;
}
//----------------------------------------------------------------------------

bool University::ListFaculties()
{
  for(int x = 0; x < Faculties.size(); x++){
    cout << Faculties[x].id << "\t" << Faculties[x].name << endl;
  }
  cout << endl;
}

//----------------------------------------------------------------------------
bool University::ProcessTransactionFile (string fileName)
{
  ifstream fin;
  string command;
  string fName, fEmail, fAddress, fDateOfBirth, fGender, sName, sEmail, sAddress, sDateOfBirth, sGender,
    depName, depLoc, sMajor, cName;
  long depChair, fSalary, fDepId, departId, sAdvisorId, facId, cDeptId, cTaughtBy, sId, cId;
  int fYearOfExp, sYearOfStudy, cMaxSeats;
  fin.open(fileName.c_str());
  if(!fin.is_open()){
    return failure;
  }
  
  fin >> command;
  while(fin){
    if(command == "CreateNewDepartment"){
      fin >> depName >> depLoc >> depChair;
      cout << "### Creating department [" << depName << "]. ###" << endl;
      CreateNewDepartment(depName, depLoc, depChair);
    }
    else if(command == "ListDepartments"){
      cout << "### Current Departments: ###" << endl;
      ListDepartments();
    }
    else if(command == "CreateNewFaculty"){
      fin >> fName >> fEmail >> fAddress >> fDateOfBirth >> fGender >> fSalary >> fYearOfExp >> fDepId;
      CreateNewFaculty(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);
    }
    else if(command == "ListFaculties"){
      cout << "### Current Faculty: ###" << endl;
      ListFaculties();
    }
    else if(command == "ListFacultiesInDepartment"){
      fin >> departId;
      cout << "### Faculty in Department [" << departId << "]. ###";
      ListFacultiesInDepartment(departId);
    }
    else if(command == "CreateNewStudent"){
      fin >> sName >> sEmail >> sAddress >> sDateOfBirth >> sGender >> sYearOfStudy >> sMajor >> sAdvisorId;
      CreateNewStudent(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);
    }
    else if(command == "ListStudents"){
      cout << "### Current Students: ###" << endl;
      ListStudents();
    }
    else if(command == "ListStudentsOfAFaculty"){
      fin >> facId;
      cout << "### Current Students of Faculty [" << facId << "]: ###";
      ListStudentsOfAFaculty(facId);
    }
    else if(command == "CreateNewCourse"){
      fin >> cName >> cDeptId >> cTaughtBy >> cMaxSeats;
      CreateNewCourse(cName, cDeptId, cTaughtBy, cMaxSeats);
    }
    else if(command == "ListCourses"){
      cout << "### Current Courses: ###" << endl;
      ListCourses();
    }
    else if(command == "ListCoursesTaughtByFaculty"){
      fin >> facId;
      cout << "### Courses Taught by Faculty [" << facId << "]: ###";
      ListCoursesTaughtByFaculty(facId);
    }
    else if(command == "ListCoursesOfADepartment"){
      fin >> departId;
      cout << "### Current Courses in Department [" << departId << "]: ###";
      ListCoursesOfADepartment(departId);
    }
    else if(command == "AddACourseForAStudent"){
      fin >> cId >> sId;
      AddACourseForAStudent(cId, sId);
    }
    else if(command == "ListCoursesTakenByStudent"){
      fin >> sId;
      cout << "### Current Courses for Student [" << sId << "]: ###";
      ListCoursesTakenByStudent(sId);
    }
    else if(command == "DropACourseForAStudent"){
      fin >> cId >> sId;
      DropACourseForAStudent(cId, sId);
    }
    else if(command == "AssignDepartmentChair"){
      fin >> facId >> departId;
      AssignDepartmentChair(facId, departId);
    }
    else if(command == "AssignInstructorToCourse"){
      fin >> facId >> cId;
      AssignInstructorToCourse(facId, cId);
    }
    
    fin >> command;
  }
}

bool University::chairExists(long depChairId){
  for(int x = 0; x < Faculties.size(); x++){
    if(Faculties[x].id == depChairId)
      return success;
  }
  return failure;
}

bool University::majorExists(string sMajor){
  for(int x = 0; x < Departments.size(); x++){
    if(Departments[x].name == sMajor)
      return success;
  }
  return failure;
}

bool University::facultyExists(long fFacId){
  for(int x = 0; x < Faculties.size(); x++){
    if(Faculties[x].id == fFacId)
      return success;
  }
  return failure;
}

bool University::deptExists(long depId){
  for(int x = 0; x < Departments.size(); x++){
    if(Departments[x].id == depId)
      return success;
  }
  return failure;
}

bool University::studentExists(long sId){
  for(int x = 0; x < Students.size(); x++){
    if(Students[x].id == sId)
      return success;
  }
  return failure;
}

bool University::courseExists(long cId){
  for(int x = 0; x < Courses.size(); x++){
    if(Courses[x].CRN == cId)
      return success;
  }
  return failure;
}
