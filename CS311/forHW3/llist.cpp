
//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A
//Make sure all if-then-else are commented describing which case it is
//Make sure all local variables are described fully

// ====================================================

HW3P1 llist
Your name: **
Complier:  **
File type: **

//=====================================================

#include"llist.h" 

Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.

Destructor  
- while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."

boolean isEmpty()
- return true if Front and Rear are both pointing to NULL.
- (note: do not use Count for this!!!)

void displayAll()
- displays each element of the list starting from Front in [ ].
- (special case: if the list is empty, display [ empty ] ).

void addRear(el_t NewNum) 
- 2 cases
- adds a new node at the rear and puts NewNum in the Elem field
  of this new node. Count is updated.
- (special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it.)
Regular case:
Rear->Next = new Node;
Rear = Rear->Next;
Rear->Elem = NewNum;
Rear->Next = NULL;

void deleteFront(el_t& OldNum)
- 3 cases
-  error case: if the List is empty, throw an exception.
-  else give back the front node element through OldNum (pass by reference)
   and also remove the front node. Count is updated.
-  (special case: if this is going to make the list empty,
    make sure both Front and Rear become NULL).
Regular case:
OldNum = Front->Elem;
Node *Second;
Second = Front->Next;
delete Front;
Front = Second;

void addFront(el_t NewNum)
- 2 cases
- will add a new node to the front of the list. Count is updated.
- (special case: if this is going to be the very first node, you must
  create a new node and make Front and Rear point to it.)
Regular case:
Node *x;
x = new Node;
x->Next = Front;
Front = x;
Front->Elem = NewNum;

void deleteRear(el_t& OldNum)
- 3 cases
- error case: if empty, throw an exception.
- else give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
- (special case: if this is going to make the list empty,
   make sure both Front and Rear become NULL).
Regular case:
OldNum = Rear->Elem;
Node *p;
Make p go to the one right before rear (using while)
delete Rear;
Rear = p;

void deleteIth(int I, el_t& OldNum)
- 4 cases
- will delete the Ith node (I starts out at 1).  Count is updated.
- Error cases: 
  If I is an illegal value (i.e. > Count or < 1) throw an exception.
- (note: this may simply call deleteFront or deleteRear for some cases)

void addbeforeIth(int I, el_t newNum)
- 4 cases
-  will add right before the Ith node.  Count is updated.
-  Error cases:
   If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.      
-  (note: this may simply call addFront or addRear for some cases)


