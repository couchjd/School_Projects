#include <vector>
#include <string>

using namespace std;

class Student{
protected:
  long id;
  string fName;
  string lName;
  
public:
  Student(){id = 0; fName = lName = " ";}
  Student(long sId, string fn, string ln){
    id = sId;
    fName = fn;
    lName = ln;   
  }
};

class Stack{
protected:
  vector<Student> v;
  int maxSize;

public:
  Stack(){maxSize = 5;}
  Stack(int mSize){maxSize = mSize;}
  bool push(long sId, string fn, string ln);
  bool pop();
  Student topOfStack();
  bool isFull();
  bool isEmpty();
};

bool Stack::isFull(){
  return(v.size() == maxSize);

}

bool Stack::isEmpty(){
  return(v.size() == 0);
}

bool Stack::push(long sId, string fn, string ln){
  if(isFull())
    return false;
  Student s(sId, fn, ln);
  v.insert(v.begin(), s);
}

bool Stack::pop(){
  if(isEmpty())
    return false;
  v.erase(v.begin());
}

Student Stack::topOfStack(){
  Student s;
  if(isEmpty())
    return s;
  s = v[0];
  return s;
}
