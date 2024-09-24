#include <iostream>
#include <string>


using namespace std;

class TreeI
{
public:
  int data;
  TreeI* left;
  TreeI* right;
  int size;

  TreeI()
  {
      data = 0;
      left = NULL;
      right = NULL;
      size = 0;
  }

  // Parameterised Constructor
  TreeI(int data)
  {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
      size = 0;
  }
  TreeI(TreeI* n)
  {
      this->data = n->data;
      this->left = NULL;
      this->right = NULL;
      size = 0;
  }
  
  
  
};