/**
 * family.h
 *
 *
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (11.20.2014)
 **/
#include <string>
#include "husband.h"
#include "wife.h"
#include "child.h"

using namespace std;

class Family
{
 protected: 
  //Pointer to first element of list of families.
  Husband* top;
 public:
  //Default constructor
  Family();

  //AddHusband creates a new Husband object and adds it 
  //to the beginning of the list of families.
  //@param SSN -- SSN of Husband
  //@param Fname - first name of Husband
  //@param Lname - last name of Husband
  void AddHusband(long SSN, string Fname, string Lname);

  //RemoveHusband deletes a Husband object (designated by SSN) from
  //the list of families.
  //@param SSN - SSN of Husband to be removed.
  void RemoveHusband(long SSN);

  //AddWife creates a Wife object and points the correct Husband object
  //to that object.
  //@param SSN - SSN of Wife
  //@param Fname - first name of Wife
  //@param Lname - last name of Wife
  //@param husbandSSN - SSN of Husband
  void AddWife(long SSN, string Fname, string Lname, long husbandSSN);

  //RemoveWife deletes a Wife object from the designated Husband object
  //@param husbandSSN - SSN of husband to remove wife from.
  void RemoveWife(long husbandSSN);

  //AddAChild adds a child to the family of the designated husband.
  //@param SSN - SSN of Child
  //@param Fname - first name of Child
  //@param Lname - last name of Child
  //@param fatherSSN - SSN of Father
  void AddAChild(long SSN, string Fname, string Lname, long fatherSSN);

  //RemoveAChild removes a Child object from the designated family.
  //@param FatherSSN - SSN of Father of family to remove Child from.
  //@param childSSN - SSN of Child to remove.
  void RemoveAChild(long FatherSSN, long childSSN);

  //PrintAFamily prints all information about each member of the
  //designated family.
  //@param fatherSSN - SSN of father of family to print.
  void PrintAFamily(long fatherSSN);

  //PrintAllFamilies prints all information about each member of 
  //all families in the list.
  void PrintAllFamilies();

  //ReadTransactionFile reads in all data from the transaction file
  //and executes actions according to the data in the file.
  void ReadTransactionFile();

  //search searches the list for a Husband object matching husbandId and
  //returns a pointer to the Husband if found.
  //@param husbandId - SSN of husband to search for.
  Husband* search(long husbandId);
};
