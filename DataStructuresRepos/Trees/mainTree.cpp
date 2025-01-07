#include <iostream>
#include "TreeI.h"
#include <string>
#include "TreeS.h"
#include <math.h>
#include "TreeA.h"
#include <vector>
#include <queue>
#include "BTrees.h"
#include "FamTree.h"

using namespace std;


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
    // Kiel* root = new Kiel;
    // insertChild(root,"OG","Damon Kiel");
    // insertChild(root,"Damon Kiel","Donna Kiel");
    // insertChild(root,"Damon Kiel","Danna Kiel");
    // insertChild(root,"Danna Kiel","Ali Kiel");
    // insertChild(root,"Donna Kiel","Ahmed Kiel");
    // printFam(root);
    bTrees tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);
    tree.print(tree.root);
    tree.isIn(tree.root,7);
    tree.isIn(tree.root,35);

    
    // return 0;
  // int arr[7]  = {4,2,6,3,5,1,7};
  // TreeI* tree1 = new TreeI;
  // arrToTree(tree1,arr,7);
  // if(isavl(tree1)){
  //   cout<<"true"<<endl;
  // }
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