#include <iostream>
#include "TreeI.h"
#include <string>
#include "TreeS.h"
#include <math.h>
#include "TreeA.h"
#include <vector>
#include <queue>
#include "BTrees.h"

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

void prettyPrintString(TreeS* tree, int depth = 0) 
{
  if(tree != NULL)
  {
    prettyPrintString(tree->right, depth + 1);
    cout << string(depth * 2, ' ');
    cout << tree->data << endl;
    prettyPrintString(tree->left, depth + 1);

  }

}
int search(string arr[], int strt, int end, string value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

TreeS* buildUtil(string in[], string post[], int inStrt, int inEnd, int* pIndex)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Postorder traversal using
       postIndex and decrement postIndex */
    TreeS* node = new TreeS(post[*pIndex]);
    (*pIndex)--;
 
    /* If this node has no children then return */
    if (inStrt == inEnd){
        return node;
    }
        
 
    /* Else find the index of this node in Inorder
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->data);
 
    /* Using index in Inorder traversal, construct left and
       right subtrees */
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
 
    return node;
}

TreeS* buildTree(string in[], string post[], int n)
{
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
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
  if (tree != NULL) 
  {
    inOrder(tree->left);
    cout << tree->data << " ";
    inOrder(tree->right);
  } 

}

void preOrder (TreeI* tree) 
{
 if(tree != NULL)
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
void UIExperience(TreeS* root,vector<string>& s){
    if(root->right == NULL && root->left == NULL){
        cout<<"You have "<<s[0]<<" hair. You desire the "<<s[2]<<" variation of the "<<s[1]<<" style.";
    }
    else{
        cout<<"You are in the "<<root->data<<" section. Are you interest in "<<root->right->data<<" or "<<root->left->data<<" styles. ";
        string f;
        cin>>f;
        s.push_back(f);
        // while(f != root->left->data && f != root->right->data)
        // {
        //   cout<<"In valid selection. Please select between "<<root->right->data<<" or "<<root->left->data<<". ";
        //   cin>>f;
        // }
        if(f == root->left->data){
            UIExperience(root->left,s);
        }      
        else{
            UIExperience(root->right,s);
        }  
    }
}
vector<vector<int> > levelOrder(TreeI* root) {
        
        queue<TreeI*> q;
        vector<vector<int> > lorder;
        if(!root) {
            return lorder;
        }
        q.push(root);
        while(!q.empty()){ // 3
            vector<int> checker; 
            int qSize = q.size();
            for(int i =0; i < qSize; i++){// 1                TreeNode* curr = q.front();
                TreeI* curr = q.front();
                q.pop();
                checker.push_back(curr->data);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right); 
                }
            }
            lorder.push_back(checker);  
        }
       return lorder;
     }
string spaces(int x){
  string s = "";
  for(int i = 0;i < x;i++){
    s+=" ";
  }
  return s;
}
void printTree2(TreeI* root){
  vector<vector<int> > v = levelOrder(root);
  int x = v.size()+1;
  if(!v.size()%2){
    x = x-1;
  }
  string space = spaces(x);
  for(int i = 0;i < v.size();i++){
    space = spaces(x);
    for(int a = 0; a < v[i].size();a++){

      if(x != 1){
        cout<<spaces(x)<<v[i][a]<<spaces(x-to_string(x).length());
      }
      else{
        cout<<space<<v[i][a];
      }
      
    }
    cout<<endl;
    x = x/2;
  }
}
 
int main() 
{  
    bTrees tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    
    tree.print(tree.root); // Print the tree structure
    
    return 0;
  // int arr[7]  = {4,2,6,3,5,1,7};
  // TreeI* tree1 = arrToTree(arr, 7);
  // prettyPrint(tree1);
    // string postOrder[15] = {"Spiral","360","Waves","High Top","Low Taper","Fade","Short","Straight Back","With Bun","Cornrows","2 Stran","Locs","Twists","Long","Hair"};
  // string inOrder[15] =   {"Spiral","Waves","360","Short","High Top","Fade","Low Taper","Hair","Straight Back","Cornrows","With Bun","Long","2 Stran","Twists","Locs"};
  // TreeS* dec = buildTree(inOrder,postOrder,15);
  // vector<string> s;
  // UIExperience(dec,s);
  // cout<<x;
  // int arr2[4] = {5,2,1,3};
  // TreeI* tree2 = arrToTree(arr2, 4);
  
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