#include <vector>
#include <string>
#include "StudentProfile.h"

using namespace std;

class StudentCollection
{
 private:
  vector<StudentProfile> stCollection;

 public:
  void getInfo();
  void printCollection();
};
