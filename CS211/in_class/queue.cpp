class Student{
  typedef Student* stuPtr;
protected:
  long id;
  string fName;
  string lName;
  stuPtr nextStu;

public:
  Student(){ id = 0; fName = lName = " "; nextStu = NULL;}
  Student(long stId, string fn, string ln){
    id = stId;
    fName = fn;
    lName = ln;
    nextStu = NULL;
  }
};

class Queue{
protected:
  stuPtr top;
  int size;
  int maxSize;

public:
  Queue(){top = NULL; size = 0; maxSize = 5;}
  Queue(int mSize){top = NULL; size = 0; maxSize = mSize;}
  bool push(long stId, string fn, string ln);
  bool pop();
  stuPtr topOfQueue();
  bool isEmpty();
  bool isFull();
};

bool Queue::isEmpty(){
  return((size == 0) || (top == NULL));  
}

bool Queue::isFull(){
  return(size == maxSize);
}

bool Queue::push(long stId, string fn, string ln){
  if(isFull())
    return false;
  stuPtr p = new Student(sId, fn, ln);
  if(top == NULL){
    top = p;
  }
  else{
    stuPtr q = top;
    while(q-nextStu != NULL)
      q = q->nextStu;
    q->nextStu = p;
  }
  size++;
  return true;
}

bool Queue::pop(){
  if(isEmpty())
    return false;
  stuPtr p = top;
  top = top->nextStu;
  delete p;
  size--;
  return true;
}

stuPtr topOfQueue(){
  return top;
}

int main(){
  Queue cs211(60);
  cs211.push();
}
