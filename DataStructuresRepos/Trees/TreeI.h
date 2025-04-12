#include <iostream>
#include <vector>
using namespace std;

struct TreeI {
  int data;
  TreeI* right;
  TreeI* left;
  int height;  // new height field (starts at 1 for leaf)
  int size;  // keeping this in case you’re using it elsewhere
  TreeI(){
    right = nullptr;
    left = nullptr;
    height = 1;  // new height field (starts at 1 for leaf)
    size = 0;
  }
};

void insert(TreeI* tree, int n) 
 {
   if(tree == nullptr) 
   {
    TreeI* newRoot = new TreeI;
    newRoot->data = n;
    tree = newRoot;
    tree->size++;
   } 
   else if (tree->data < n) 
   {
     if (tree->right == nullptr) 
     {
       TreeI* newRoot = new TreeI;
       newRoot->data = n;
       tree->right = newRoot;
       tree->size++;
     }
     else insert(tree->right, n);
   } 
   else if (tree->data > n) 
   {
     if ( tree->left == nullptr) 
     {
       TreeI* newRoot = new TreeI;
       newRoot->data = n;
       tree->left = newRoot;
       tree->size++;
     }
    else insert(tree->left, n);
   }
 }

void prettyPrint(TreeI* tree, int depth = 0) 
{
  if(tree != NULL)
  {
    prettyPrint(tree->right, depth + 1);
    cout << string(depth * 2, ' ');
    cout << tree->data << endl;
    prettyPrint(tree->left, depth + 1);

  }

}


void arrToTree(TreeI* tree, int arr[], int len)
{
  tree->data = arr[0];
  for(int i = 1; i < len; i++)
  {
    insert(tree, arr[i]);
  }
  // prettyPrint(tree);
}



// TreeI* arrToTreeS(int arr[], int size)
// {
//   for(int i = 1; i < size; i++)
//   {
//     insert(tree, arr[i]);
//   }
//   // prettyPrint(tree);
//   return tree;
// }
bool isIn(TreeI* tree, int val)
{
  if(tree == NULL){
    return false;

  }
  else if(val == tree->data){
    return true;

  }
  else if(val < tree->data)
  {
    return isIn(tree->left, val);
  }
  else
  {
    return isIn(tree->right, val);
  } 
  
}


void countNodesHelper(TreeI* root, int& counter) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    counter++;
    return;
  }
  if (root->left == NULL) {
    counter++;
    countNodesHelper(root->right, counter);
  }
  else if (root->right == NULL) {
    counter++;
    countNodesHelper(root->left, counter);
  }
  else {
    counter++;
    countNodesHelper(root->left, counter);
    countNodesHelper(root->right, counter);
  }
}

int countNodes(TreeI* root) {
  int counter = 0;
  countNodesHelper(root, counter);
  return counter;
}


void inOrder(TreeI* tree) 
{
  if (tree != nullptr) 
  {
    inOrder(tree->left);
    cout<<tree->data<<" ";
    inOrder(tree->right);
  } 
}

void preOrder (TreeI* tree) 
{
 if(tree != nullptr)
 {
   cout<<tree->data<<" ";
   preOrder(tree->left);
   preOrder(tree->right);
 }
}



int amtNodept2(TreeI* tree, int size){
  if(tree == nullptr)
  {
    return 0;
  }
  if(tree->left == nullptr && tree->right == nullptr)
  {

    return 1 + amtNodept2(tree->left,size);
  }

  if(tree->left != nullptr && tree->right == nullptr)
  {

    return 1 +amtNodept2(tree->left,size);   
  }
  else if(tree->right != nullptr && tree->left == nullptr)
  {

    return 1 + amtNodept2(tree->right,size);   
  }
  else if(tree->left != nullptr  && tree->right != nullptr)
  {
    
       return 1 + amtNodept2(tree->left,size) + amtNodept2(tree->right,size);
  }

  return size;
}
void orderIn(TreeI* tree)
{
  if(tree == nullptr)
  {
    cout<< ". ";
  }
  else{
    orderIn(tree->left);
    cout<<tree->data<<" ";
    orderIn(tree->right);
  }
}
void postOrder(TreeI* tree)
{
  if(tree != nullptr){
    postOrder(tree->left);
    postOrder(tree->right);
    cout<<tree->data<<" ";
  }
}

// bool isavl(TreeI* tree)
// {
//   if(tree == nullptr){
//     return true;
//   }
//   else if(abs(Difference(tree)) > 1) 
//   {
//     cout<<tree->data<<endl;
//     return false;
//   }
//   else
//   {
//     return isavl(tree->left) && isavl(tree->right);
//   }
// }



bool IsIn(TreeI* tree, int val){
  if(tree == NULL){
    return false;
  }
  else if(tree->data == val){
    return true;
  }
  else if(tree->data > val){
    return IsIn(tree->left,val);
  }
  else{
    return IsIn(tree->right,val);
  }
}
bool isBST(TreeI* tree)
{
  if(tree == nullptr)
  {
    return true; 
  }
  else if(tree->left == nullptr && tree->right == nullptr)
  {
    return true;
  }
  else
  {
    if((tree->left != nullptr && tree->left->data <= tree->data) && tree->right == nullptr)
    {
      return isBST(tree->left);   
    }
    else if((tree->right != nullptr && tree->right->data >= tree->data) && tree->left == nullptr)
    {
        return isBST(tree->right);   
    }
    else if((tree->left != nullptr && tree->left->data <= tree->data) && (tree->right != nullptr && tree->right->data >= tree->data))
    {
      return isBST(tree->left) && isBST(tree->right);
    }
    else
    {
      return false;
    }
  }
}
  
int getHeight(TreeI* node) {
  if(node){
    return node->height;
  }  
  else{
    return 0;
  }
}
void updateHeight(TreeI* node) {
  if (node){
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  }
      
}
int getBalance(TreeI* node) {
  return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
TreeI* RotateRight(TreeI* tree)
{
  TreeI* R = tree->left;
  TreeI* L = R->right;
  R->right = tree;
  tree->left = L;
  updateHeight(tree);
  updateHeight(R);
  return R;
}

TreeI* RotateLeft(TreeI* tree)
// Returns the tree I resulting from a left rotation.
{
  TreeI* S = tree->right;
  TreeI* B = S->left;
  S->left = tree;
  tree->right = B;
  updateHeight(tree);
  updateHeight(S);
  return S;
}

TreeI* RotateRightLeft(TreeI* T)
// Returns the tree I resulting from a right-left rotation.
{
  TreeI* S = T->right;
  T->right = RotateRight(S);
  return RotateLeft(T);
}

TreeI* RotateLeftRight(TreeI* T)
// Returns the tree I resulting from a left-right rotation.
{
  TreeI* S = T->left;
  T->left = RotateLeft(S);
  return RotateRight(T);
}

TreeI* Balance(TreeI* T) {
  int balanceFactor = getBalance(T);

  if (balanceFactor > 1) {
    // Left-heavy
    if (getBalance(T->left) >= 0)
      return RotateRight(T);       // Left-Left
    else
      return RotateLeftRight(T);   // Left-Right
  }
  else if (balanceFactor < -1) {
    // Right-heavy
    if (getBalance(T->right) <= 0)
      return RotateLeft(T);        // Right-Right
    else
      return RotateRightLeft(T);   // Right-Left
  }

  return T; // Already balanced
}

TreeI* InsertAVL(TreeI* root, int value) {
  if (root == nullptr) {
      TreeI* newNode = new TreeI;
      newNode->data = value;
      return newNode;
  }

  if (value < root->data){
    root->left = InsertAVL(root->left, value);
  }
  else if (value > root->data){
    root->right = InsertAVL(root->right, value);
  } 
  else{
    return root; 
  }
  updateHeight(root);           // Update height after insertion
  return Balance(root);         // Balance the node if needed
}

TreeI* vecToTree(vector<int>& arr){
  TreeI* tree = nullptr;
  for(int i = 0; i < arr.size(); i++)
  {
    tree = InsertAVL(tree, arr[i]);
  }
  return tree;
}

void inOrderV(vector<int>& meep, TreeI* root){
  if(root == NULL){
      return;
  }
  else{
    inOrderV(meep,root -> left);
    meep.push_back(root -> data); 
    inOrderV(meep, root -> right);
       
  }
}
vector<int> treeSort(vector<int>& arr){
  TreeI* root = vecToTree(arr);
  vector<int> answer;
  inOrderV(answer, root);
  return answer;
}
void cloneTree(TreeI* OG, TreeI*& clone) {
    if (!OG) {
        clone = nullptr;
        return;
    }
    
    clone = new TreeI;
    clone->data = OG->data;

    cloneTree(OG->left, clone->left);
    cloneTree(OG->right, clone->right);
}
