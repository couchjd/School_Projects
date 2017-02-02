/**
 * family.cpp
 *
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (11.20.2014)
 **/
#include "family.h"
#include <iostream>
#include <fstream>


Husband* top;

Family::Family(){
  top = NULL;
}


//Local variables.
//Husband* p - pointer to Husband object
void Family::AddHusband(long SSN, string Fname, string Lname){
  //check if husband already exists
  if(search(SSN) != NULL){
    cout << "Husband already exists!" << endl;
    return;
  }
  //add husband to list
  Husband* p = new Husband(SSN, Fname, Lname);
  p->nextFamily = top;
  top = p;
}

//Local variables.
//Husband* p - pointer to Husband object
//Husband* q - pointer to Husband object used to redirect pointer
//             before deleting p.
void Family::RemoveHusband(long SSN){
  //Check if list is empty.
  Husband* p = search(SSN);
  if(p == NULL){
    cout << "Husband does not exist!" << endl;
  }
  //check if Wife exists
  //remove Wife if it exists.
  if(p->myWife != NULL){
    RemoveWife(SSN);
  }
  //check if list contains only one element
  if(top->nextFamily == NULL){
    delete top;
    top = NULL;
    return;
  }
  
  //redirect pointer to next Husband object.
  Husband* q = top;  
  while(q->nextFamily != p){
    q = q->nextFamily;
  }
  q->nextFamily = p->nextFamily;
  delete p;
}


//Local variables.
//Husband* p - pointer to Husband object
void Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN){
  Husband* p = search(husbandSSN);
  if(p == NULL){
    cout << "Husband does not exist." << endl;
    return;
  }
  if(p->myWife != NULL){
    cout << "Wife already exists." << endl;
    return;
  }

  p->myWife = new Wife(SSN, Fname, Lname);
}

//Local variables
//Husband* p - pointer to Husband object
void Family::RemoveWife(long husbandSSN){
  Husband* p = search(husbandSSN);
  if(p == NULL){
    cout << "Family does not exist." << endl;
    return;
  }
  if(p->myWife == NULL){
    cout << "Wife does not exist." << endl;
    return;
  }
  //remove children (if they exist) before deleting Wife object.
  while(p->myWife->myChildren != NULL){
    RemoveAChild(husbandSSN, p->myWife->myChildren->SSN);    
  }
  delete p->myWife;
  p->myWife = NULL;
}

//Local variables:
//Husband* p - pointer to Husband object
//Child* c - pointer to Child object
void Family::AddAChild(long SSN, string Fname, string Lname, long fatherSSN){
  Husband* p = search(fatherSSN);
  if(p == NULL){
    cout << "Father does not exist." << endl;
    return;
  }
  if(p->myWife == NULL){
    cout << "Mother does not exist." << endl;
    return;
  }
  
  Child* c = p->myWife->myChildren;
  while(c != NULL){
    //check if Child with SSN already exists.
    if(c->SSN == SSN){
      cout << "Child with SSN [" << SSN << "] already exists." << endl;
      return;
    }
    c = c->mySibling;
  }
  //add new child to top of p->myWife->myChildren
  c = new Child(SSN, Fname, Lname);
  c->mySibling = p->myWife->myChildren;
  p->myWife->myChildren = c;
}


//Local variables:
//Husband* p - pointer to Husband object
//Child* c - pointer to Child object
//Child* c2 - pointer to Child object. Used to redirect
//            mySibling pointer when deleting a Child object.
void Family::RemoveAChild(long fatherSSN, long childSSN){
  Husband* p = search(fatherSSN);
  if(p == NULL){
    cout << "Father does not exist." << endl;
    return;
  }
  if(p->myWife == NULL){
    cout << "Mother does not exist." << endl;
    return;
  }

  Child* c = p->myWife->myChildren;
  Child* c2 = p->myWife->myChildren;
  //Check if any Child exists
  if(c == NULL)
    return;
  
  //Check if only one child exists
  if(c->mySibling == NULL){
    if(c->SSN == childSSN){
      delete c;
      c = NULL;
    }
    return;
  }
  
  //Search for SSN in list of Child objects.
  while(c->mySibling != NULL){
    if(c->SSN == childSSN){
      break;
    }
    c = c->mySibling;
  }
  
  //Point c2 to Child object previous to c.
  while(c2->mySibling != c){
    c2 = c2->mySibling;
  }
  
  //Redirect c2->mySibling and delete c.
  c2->mySibling = c->mySibling;
  delete c;
}

//Local variables:
//Husband* p - pointer to Husband object
Husband* Family::search(long husbandId){
  Husband* p = top;
  while(p != NULL){
    if(p->SSN == husbandId){
      return p;
    }
    p = p->nextFamily;
  }
  return NULL;
}

//Local variables:
//Husband* p - pointer to Husband object
//Wife* w - pointer to Wife object
//Child* c - pointer to Child object
void Family::PrintAFamily(long fatherSSN){
  Husband* p = search(fatherSSN);
  if(p == NULL){
    cout << "Family does not exist." << endl;
    return;
  }
  cout << "======================================================================" << endl;
  cout << "Father:" << endl;
  cout << "SSN: " << p->SSN << "\tName: " << p->firstName << " " << p->lastName << endl;
  if(p->myWife != NULL){
    Wife* w = p->myWife;
    cout << "Mother:" << endl;
    cout << "SSN: " << w->SSN << "\tName: " << w->firstName << " " << w->lastName << endl;
    Child* c = w->myChildren;
    while(c != NULL){
      cout << "Child:" << endl;
      cout << "SSN: " << c->SSN << "\tName: " << c->firstName << " " << c->lastName << endl;
      c = c->mySibling;
    }
  }
  cout << "======================================================================" << endl;
}

//Local variables:
//Husband* p - pointer to Husband object
void Family::PrintAllFamilies(){
  Husband* h = top;
  while(h != NULL){
    PrintAFamily(h->SSN);
    h = h->nextFamily;
  }
}


//Local variables:
//fstream fin - file input stream from "transaction.txt"
//string command - string representation of command to be executed
//string fName - first name of object to be acted upon
//string lName - last name of object to be acted upon
//long fatherSSN - SSN of Father objects
//long motherSSN - SSN of Mother objects
//long childSSN - SSN of Child objects
void Family::ReadTransactionFile(){
  fstream fin;
  string command, fName, lName;
  long fatherSSN, motherSSN, childSSN;
  fin.open("transaction.txt");
  while(!fin.eof()){
    fin >> command;
    //    cout << "COMMAND IS: [" << command << "]." << endl;
    if(command == "AddHusband"){
      fin >> fatherSSN >> fName >> lName;
      AddHusband(fatherSSN, fName, lName);
    }
    if(command == "AddWife"){
      fin >> motherSSN >> fName >> lName >> fatherSSN;
      AddWife(motherSSN, fName, lName, fatherSSN);
    }
    if(command == "AddAchild"){
      fin >> childSSN >> fName >> lName >> fatherSSN;
      AddAChild(childSSN, fName, lName, fatherSSN);
    }
    if(command == "RemoveAchild"){
      fin >> fatherSSN >> childSSN;
      RemoveAChild(fatherSSN, childSSN);
    }
    if(command == "PrintAFamily"){
      fin >> fatherSSN;
      PrintAFamily(fatherSSN);
    }
    if(command == "PrintAllFamilies"){
      PrintAllFamilies();
    }
  }
}

