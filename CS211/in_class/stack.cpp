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

class Stack{
protected:
  stuPtr top;
  int size;
  int maxSize;

public:
  Stack(){top = NULL; size = 0; maxSize = 5;}
  Stack(int mSize){top = NULL; size = 0; maxSize = mSize;}
  bool push(long stId, string fn, string ln);
  bool pop();
  stuPtr topOfStack();
  bool isEmpty();
  bool isFull();
};

bool Stack::isEmpty(){
  return((size == 0) || (top == NULL));  
}

bool Stack::isFull(){
  return(size == maxSize);
}

bool Stack::push(long stId, string fn, string ln){
  if(isFull())
    return false;
  stuPtr p = new Student(sId, fn, ln);
  p->nextStu = top;
  top = p;
  size++;
  return true;
}

bool Stack::pop(){
  if(isEmpty())
    return false;
  stuPtr p = top;
  top = top->nextStu;
  delete p;
  size--;
  return true;
}

stuPtr topOfStack(){
  return top;
}

int main(){
  Stack cs211(60);
  cs211.push();
}
