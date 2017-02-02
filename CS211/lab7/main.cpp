#include "adjunct.h"
#include "tenure.h"

int main(){
  AdjunctProf a1;
  a1.SetValues("Adam Smith", 12345, "asmith@csusm.edu", 'M', 1, 2);
  a1.findSalary();
  a1.print();

  TenureTrackProf t1;
  t1.SetValues("Jim Anderson", 54321, "janderson@csusm.edu", 'S', 8);
  t1.findSalary();
  t1.print();
  return 0;
}
