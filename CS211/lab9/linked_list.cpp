//*******************************************************************************************
//CS 211 - Lab 9
//Complete the program Lab09(Program).cpp and implement the routines that are not implemented
//*******************************************************************************************


/* Use the comments given in each routine to complete the following program */


#include <iostream>
#include<string>
#include <fstream>

using namespace std;

class Node;
typedef Node* NodePtr;

class LL;
class Node 
{
  friend class LL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr nextStudent;
public:
  Node();
  Node(int id, string name, string email, int age);
};

class LL
{
private:
  NodePtr  top;
  void destroy (NodePtr&);

public:
  LL();
  LL(const LL& source);
  ~LL();
  void insertDataFromFile();
  void print ();
  bool search (int);
  void insertAfterFirst (int id, string name, string email, int age);
  void insertBeforeFirst (int id, string name, string email, int age);
  void insertAfterLast (int id, string name, string email, int age);
  void insertBeforeLast (int id, string name, string email, int age);
  void remove (int);
  void copy (NodePtr top1, NodePtr& top2);
};

Node::Node(){
  stId = 0;
  stName = "unknown";
  stEmail = "unknown@domain.net";
  stAge = 0;
  nextStudent = NULL;
}

Node::Node(int id, string name, string email, int age){
  stId = id;
  stName = name;
  stEmail = email;
  stAge = age;
  nextStudent = NULL;
}

//--------------------------------------------
//--------------------------------------------
// the default constructor
LL::LL()
{
  top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& source)
{
  top = NULL;
  copy(source.top, top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
{
  destroy(top);
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
   76543Marymary@csusm.edu19
   98765Kathykathy@csusm.edu30
   16438Floraflora@csusm.edu25
   43260Peterpeter@csusm.edu29
   87590kimkim@csusm.edu31
*/
void LL::insertDataFromFile()
{
  ifstream fin;
  long id;
  string name;
  string email;
  int age;
  fin.open("data.txt");
  if(fin.is_open()){
    fin >> id >> name >> email >> age;
    insertAfterLast(id, name, email, age);

    while(fin){
      if(fin.eof())
	break;
      fin >> id >> name >> email >> age;
      insertAfterLast(id, name, email, age);
    }
  }
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void LL::print ()
{
  NodePtr p = top;
  cout << "=========================PRINTING==========================" << endl;
  while(p != NULL){
    cout << p->stId << "\t" << p->stName << "\t" << p->stEmail << "\t" << p->stAge << endl;
    p = p->nextStudent;
  }
  cout << "===========================================================" << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool LL::search (int id)
{
  NodePtr p = top;
  
  while(p != NULL){
    if(p->stId == id)
      return true;
    p = p->nextStudent;
  }
  return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertAfterFirst (int id, string name, string email, int age)
{
  if(top == NULL){
    insertBeforeFirst(id, name, email, age);
    return;
  }

  NodePtr p = new Node(id, name, email, age);
  NodePtr q = top;
  p->nextStudent = q->nextStudent;
  q->nextStudent = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
  NodePtr p = new Node(id, name, email, age);
  p->nextStudent = top;
  top = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast (int id, string name, string email, int age)
{
  if(top == NULL){
    insertBeforeFirst(id, name, email, age);
    return;
  }
  NodePtr p = new Node(id, name, email, age);
  NodePtr q = top;
  while(q->nextStudent !=  NULL){
    q = q->nextStudent;
  }
  q->nextStudent = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast (int id, string name, string email, int age)
{
  NodePtr p = new Node(id, name, email, age);
  NodePtr q = top;
  NodePtr r = top;
  if(top == NULL)
    top = p;

  while(q->nextStudent != NULL)
    q = q->nextStudent;
  p->nextStudent = q;

  while(r->nextStudent != q)
    r = r->nextStudent;
  r->nextStudent = p;  
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove (int id)
{
  NodePtr p = top;
  NodePtr q;
  if(search(id)){
    while(p->stId != id){
      q = p;
      p = p->nextStudent;
    }
    q->nextStudent = p->nextStudent;
    delete p;
  }
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void LL::copy (NodePtr atop, NodePtr& btop)
{
  NodePtr a = atop;
  NodePtr b;

  btop = new Node(a->stId, a->stName, a->stEmail, a->stAge);
  b = btop;
  a = a->nextStudent;

  while(a != NULL){
    b->nextStudent = new Node(a->stId, a->stName, a->stEmail, a->stAge);
    
    b = b->nextStudent;
    a = a->nextStudent;
  }
}
//--------------------------------------------
// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{
  NodePtr p = top;
  NodePtr q = top;

  while(p != NULL){
    p = p->nextStudent;
    delete q;
    q = p;
  }
  top = NULL;
}

//--------------------------------------------

int main () 
{
  LL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  
  list1.print();
  bool  found = list1.search (12321);
  if (found)
    cout << "the record was found" << endl;
  else
    cout << "the record was not found" << endl;

  cout << "removing" << endl;

  list1.remove (54321);

  cout << "removed" << endl;

  list1.print();

  cout << "printed" << endl;
  
  LL list2(list1);
  
  cout << "copied" << endl;
  list2.print();

  return 0;

}
//--------------------------------------------
