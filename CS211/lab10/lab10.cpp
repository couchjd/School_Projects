//********************************************************************************************
// CS 211 - Lab 10
// Complete the program Lab10(Program).cpp and implement the routines that are not implemented
//********************************************************************************************

/* Use the comments given in each routine to complete the following program */

#include <iostream>
#include<string>
#include <fstream>

using namespace std;

class Node;
typedef Node* NodePtr;

class CircularDLL;
class Node 
{
  friend class CircularDLL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr next;
  NodePtr prev;
public:
  Node();
  Node(int id, string name, string email, int age);
};

class CircularDLL
{
private:
  NodePtr  top;
  void destroy (NodePtr&);

public:
  CircularDLL();
  CircularDLL(const CircularDLL& source);
  ~CircularDLL();
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
  next = this;
  prev = this;
}

Node::Node(int id, string name, string email, int age){
  next = this;
  prev = this;
  stId = id;
  stName = name;
  stEmail = email;
  stAge = age;
}

//--------------------------------------------
//--------------------------------------------
// the default constructor
CircularDLL::CircularDLL()
{
  top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{

}

//--------------------------------------------
//--------------------------------------------
// the destructor
CircularDLL::~CircularDLL()
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
void CircularDLL::insertDataFromFile()
{
  fstream fin;
  long stId;
  int stAge;
  string stName, stEmail;
  fin.open("transaction.txt");
  fin >> stId >> stName >> stEmail >>stAge;
  //  cout << stId << " " << stName << " " << stEmail << " " << stAge << endl;
  insertBeforeFirst(stId, stName, stEmail, stAge);

  while(fin){
    if(fin.eof())
      break;
    fin >> stId >> stName >> stEmail >> stAge;
    cout << stId << " " << stName << " " << stEmail << " " << stAge << endl;
    insertBeforeFirst(stId, stName, stEmail, stAge);
  }
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void CircularDLL::print()
{
  if(top == NULL)
    return;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

  if(top->next == top){
    cout << "PRINT ONLY ONE RECORD" << endl;
    cout << "ID: " << top->stId << "Name: " << top->stName << endl;
    return;
  }

  NodePtr p = top;
  do{
    cout << "ID: " << p->stId << "\tName: " << p->stName << endl;
    p = p->next;
  }while(p->next != top);
  cout << "++++++++++++++++++++++++++++END++++++++++++++++++++++++++++++++++" << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool CircularDLL::search (int id)
{
  NodePtr p = top;
  if(p->stId == id)
    return true;
  while(p->next != top){
    if(p->stId == id)
      return true;
    p = p->next;
  }
  return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{
  if(top == NULL){
    top = new Node(id, name, email, age);
    return;
  }
  NodePtr p = new Node(id, name, email, age);

  if(top->next == top && top->prev == top){
    top->next = p;
    top->prev = p;
    p->next = top;
    p->prev = top;
    return;
  }
  top->next = p;
  p->prev = top;
  p->next = top->next;
  p->next->prev = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)

void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{
  if(top == NULL){
    top = new Node(id, name, email, age);
    return;
  }
  NodePtr p = new Node(id, name, email, age);

  if(top->next == top && top->prev == top){
    top->next = p;
    top->prev = p;
    p->next = top;
    p->prev = top;
    top = p;
    return;
  }
  p->next = top;
  p->prev = top->prev;
  top->prev->next = p;
  top->prev = p;  
  top = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)

void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
  if(top == NULL){
    top = new Node(id, name, email, age);
    return;
  }
  NodePtr p = new Node(id, name, email, age);
  
  if(top->next == top && top->prev == top){
    top->next = p;
    top->prev = p;
    p->next = top;
    p->prev = top;
    return;
  }
  p->prev = top->prev;
  p->next = top;
  top->prev->next = p;
  top->prev = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
  if(top == NULL){
    top = new Node(id, name, email, age);
    return;
  }
  NodePtr p = new Node(id, name, email, age);

  if(top->next == top && top->prev == top){
    top->next = p;
    top->prev = p;
    p->next = top;
    p->prev = top;
    top = p;
    return;
  }
  p->prev = top->prev->prev;
  p->next = top->prev;
  top->prev->prev->next = p;
  top->prev->prev = p;
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void CircularDLL::remove (int id)
{
  NodePtr p = top;

  if(top == NULL)
    return;
  if(top->next == top){
    top = NULL;
    delete p;
    return;
  }
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void CircularDLL::copy (NodePtr atop, NodePtr& btop)
{

}       
 //--------------------------------------------
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top) 
{
  NodePtr p = top;
  while(top != NULL){
    cout << "REMOVING [" << top->stId << "]" << endl;
    remove(top->stId);
    cout << "REMOVED [" << top->stId << "]" << endl;
  }
}

//--------------------------------------------

int main () 
{
  CircularDLL list1;
  cout << "INSERTING DATA FROM FILE." << endl;
  list1.insertDataFromFile();
  cout << "INSERTED DATA FROM FILE." << endl;
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
  list1.remove (54321);
  list1.print();
   
  CircularDLL list2(list1);
  list2.print();
  return 0;
}
//--------------------------------------------
