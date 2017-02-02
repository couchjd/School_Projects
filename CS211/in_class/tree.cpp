//A tree consists of a number of connected nodes.
//A tree is an instance of a general structure called a graph.
//--A graph consists of vertices (nodes) and edges (branches).

//Binary tree has two pointers to left and right child nodes.
//Nodes are inserted according to rules:
//if new node < root, insert to left of root
//if new node > root, insert to right of root

class Node{
  friend class Tree;
  typedef Node* nodePtr;
protected:
  int num;
  nodePtr left;
  nodePtr right;
public:
  Node(){num = 0; left = right = NULL;}
  Node(int n){num = n; left = right = NULL;}
};

class Tree{
protected:
  nodePtr root;
public:
  bool insertIntoTree(nodePtr& root);
  bool search(nodePtr root);
  
  //prints from left to right in ascending order -- left->num, num, right->num -- recursively
  bool printInOrder(nodePtr root);

  //left->num, right->num, num
  bool printPostOrder(nodePtr root);

  //num, left->num, right->num
  bool printPreOrder(nodePtr root);
  int CountNodes(nodePtr root);
  bool destroy(nodePtr& root);
  int findLongestLength(nodePtr root);
  int findShortestLength(nodePtr root);
  int countNodes(nodePtr root);
  bool insertNode(nodePtr root, int key);
  int findNumOfOdds(nodePtr root);
  int countNodesDivBy2(nodePtr root);

  Tree(){root = NULL;}
  ~Tree(){destroy();}
};

bool Tree::printInOrder(nodePtr root){
  if(root == NULL)
    return false;
  printInOrder(root->left);
  cout << root->num << "\t";
  printInOrder(root->right);
}

int Tree::countNodes(nodePtr root){
  if(root == NULL)
    return 0;
  return(countNodes(root->left) + countNodes(root->right ) + 1);
}

int Tree::findLongestLength(nodePtr root){
  if(root == NULL)
    return 0;
  int l = findLongestLength(root->left);
  int r = findLongestLength(root->right);
  if(l>r)
    return l+1;
  else
    return r+1;
}

int Tree::findShortestLength(nodePtr root){
  if(root == NULL)
    return 0;
  if(root->left == NULL)
    return findShortestLength(root->right)+1;
  else if(root->right == NULL)
    return findShortestLength(root->left)+1;
  int l = findShortestLength(root->left);
  int r = findShortestLength(root->right);

  if(l < r)
    return l+1;
  else
    return r+1;
}

int Tree::countNodesDivBy2(nodePtr root){
  if(root == NULL)
    return 0;
  if(root->num % 2 == 0)
    return(countNodesDivBy2(root->left) + countNodesDivBy2(root->right) + 1);
  else
    return(countNodesDivBy2(root->left) + countNodesDivBy2(root->right));
}

void Tree::destroy(nodePtr& root){
  if(root == NULL)
    return;
  if(root->left == NULL && root->right == NULL){
    delete root;
    root = NULL;
    return;
  }
  destroy(root->left);
  destroy(root->right);
}

bool Tree::insertNode(nodePtr& root, int key){
  if(root == NULL){
    root = new Node(key);
    return true;
  }
  if(key < root->num)
    insertNode(root->left, key);  
  else
    insertNode(root->right, key);
}
