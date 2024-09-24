#include <iostream>
#include "TreeI.h"
#include <string>
#include "TreeS.h"
#include <math.h>
#include "TreeA.h"
using namespace std;


void insert(TreeI* tree, int n) 
 {
   if(tree == nullptr) 
   {
     tree = new TreeI(n);
   } 
   else if (tree->data < n) 
   {
     if (tree->right == nullptr) 
     {
       tree->right = new TreeI(n);
     }
     tree->size++;
     insert(tree->right, n);
   } 
   else if (tree->data > n) 
   {
     if ( tree->left == nullptr) 
     {
       tree->left = new TreeI(n);
     }
     tree->size++;
     insert(tree->left, n);
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

void prettyPrintString(TreeI* tree, int depth = 0) 
{
  if(tree != NULL)
  {
    prettyPrintString(tree->right, depth + 1);
    cout << string(depth * 2, ' ');
    cout << tree->data << endl;
    prettyPrintString(tree->left, depth + 1);

  }

}

TreeI* arrToTree(int arr[], int size)
{
  TreeI* tree = new TreeI(arr[0]);
  for(int i = 1; i < size; i++)
  {
    insert(tree, arr[i]);
  }
  // prettyPrint(tree);
  return tree;
}

TreeI* arrToTreeS(int arr[], int size)
{
  TreeI* tree = new TreeI(arr[0]);
  for(int i = 1; i < size; i++)
  {
    insert(tree, arr[i]);
  }
  // prettyPrint(tree);
  return tree;
}
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

int height(TreeI* tree)
{
  if(tree == NULL)
  {
    return 0;
  }
  else
  {
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);
    if(leftHeight > rightHeight)
    {
      return leftHeight + 1;
    }
    else
    {
      return rightHeight + 1;
    }
  }

}
// bool ib(TreeI* tree)
// {
//   if(tree == NULL)
//   {
//     return true;
//   }
//   if(abs(height(tree->left) - height(tree->right)) > 1)
//   {
//     return false;
//   }
//   else
//   {
//     ib(tree->left) && ib(tree->right);
//   }

// }


// bool isAVLTree(TreeI* tree)
// {
//   if(tree == NULL){

//     return true;
//   }
//   else if(abs(height(tree->left) - height(tree->right)) > 1){
//     return false;
//   }
//   else{
//     return isAVLTree(tree->left) && isAVLTree(tree->right);
//   }
// }

void inOrder(TreeI* tree) 
{
  if (tree == NULL) 
  {
    cout << ". ";
  } 
  else 
  {
    inOrder(tree->left);
    cout << tree->data << " ";
    inOrder(tree->right);
  }
}

void preOrder (TreeI* tree) 
{
 if(tree == NULL){
   cout<<". ";
 }
  else
  {
    
    cout<<tree->data<<" ";
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

/*
int amtNode(TreeI* tree){
  return tree->size+1;
}
*/

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
  if(tree == nullptr){
    cout<<". ";
  }
  else{
    postOrder(tree->left);
    postOrder(tree->right);
    cout<<tree->data<<" ";
  }
}

// bool treeEqual(TreeI* tree1, TreeI* tree2)
// {
//   if(tree1 == nullptr && tree2 == nullptr){
//     return true;
//   }
//   else if(tree1 == nullptr && tree2 != nullptr)
//   {
//     return false;
//   }
//   else if(tree2 == nullptr && tree1 != nullptr)
//   {
//     return false;
//   }
//   else if(tree1->data != tree2->data){
//     return false;
//   }
//   else
//   {
//   treeEqual(tree1->left, tree2->left) && treeEqual(tree1->right,tree2->right);
//   }  
// }
int Difference(TreeI* T)
{
  return abs(height(T->left) - height(T->right));
}
bool isavl(TreeI* tree)
{
  if(tree == nullptr){
    return true;
  }
  else if(abs(Difference(tree)) > 1) 
  {
    return false;
  }
  else
  {
    return isavl(tree->left) && isavl(tree->right);
  }
}



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
    if((tree->left != nullptr && tree->left->data <= tree->data) && 
        tree->right == nullptr)
    {
        return isBST(tree->left);   
    }
    else if((tree->right != nullptr && tree->right->data >= tree->data) && 
        tree->left == nullptr)
    {
        return isBST(tree->right);   
    }
    else if((tree->left != nullptr && tree->left->data <= tree->data) && 
      (tree->right != nullptr && tree->right->data >= tree->data))
    {
        return isBST(tree->left) && isBST(tree->right);
    }
 
    else
    {
      return false;
    }
  }
}
  

TreeI* RotateRight(TreeI* tree)
{
  TreeI* R = tree->left;
  TreeI* L = R->right;
  R->right = tree;
  tree->left = L;
  cout << "Rotates Right" << endl;
  return R;
}

TreeI* RotateLeft(TreeI* tree)
// Returns the tree I resulting from a left rotation.
{
  TreeI* S = tree->right;
  TreeI* B = S->left;
  S->left = tree;
  tree->right = B;
  cout << "Rotates Left" << endl;
  return S;
}

TreeI* RotateRightLeft(TreeI* T)
// Returns the tree I resulting from a right-left rotation.
{
  TreeI* S = T->right;
  T->right = RotateRight(S);
  cout<< "Rotates RightLeft" << endl;
  return RotateLeft(T);
}

TreeI* RotateLeftRight(TreeI* T)
// Returns the tree I resulting from a left-right rotation.
{
  TreeI* S = T->left;
  T->left = RotateLeft(S);
  cout<< "Rotates LeftRight" << endl;
  return RotateRight(T);
}

// bool isavl(TreeI* tree)
// {
//   if(abs(Difference(tree)) > 1) 
//   {
//     return false;
//   }
//   else if(tree == nullptr){
//     return true;
//   }
//   else
//   {
//     return isavl(tree->left) && isavl(tree->right);
//   }
  
// }

TreeI* Balance(TreeI* T)
// Checks and balances the subtree T.
{
  int balanceFactor = Difference(T);
  if (balanceFactor > 1) {
    if (Difference(T->left) > 1)
      return RotateRight(T);
    else
      return RotateLeftRight(T);
  }
  else if (balanceFactor < -1) {
    if (Difference(T->right) < 0)
      return RotateLeft(T);
    else
      return RotateRightLeft(T);
  }
  else
    return T;
}

int main() 
{

  // cout<<x;
  int arr[16]  = {50,72,96,94,107,26,12,11,9,2,10,25,51,16,17,95};
  // int arr2[4] = {5,2,1,3};
  TreeI* tree1 = arrToTree(arr, 16);
  // TreeI* tree2 = arrToTree(arr2, 4);
  prettyPrint(tree1);
  // cout<<endl;
  // if(isavl(tree2)){
  //   cout<<"true";
  // }
  // else{
  //   cout<<"false";
  // }
  
//   TreeA root(5);
//   root.insertA(2);
//   root.insertA(1);
//   root.insertA(3);
//   root.insertA(8);
//   root.insertA(6);
//   root.insertA(9);
//   root.insertA(4);

//   cout<<root.height()<<endl;
//   root.printTreeA();
  // cout<<endl;
  // orderIn(tree2);
  // cout<<endl;
  // preOrder(tree2); 
  // cout<<endl;
  // postOrder(tree2);
  // cout<<endl;
  // cout<<"Size: "<<amtNodept2(tree2,0);


}