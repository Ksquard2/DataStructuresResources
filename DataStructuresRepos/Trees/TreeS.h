#include <iostream>
#include <string>



using namespace std;

class TreeS
{
public:
  string data;
  TreeS* left;
  TreeS* right;
  int size;

  TreeS()
  {
      data = "";
      left = NULL;
      right = NULL;
      size = 0;
  }

  // Parameterised Constructor
  TreeS(string data)
  {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
      size = 0;
  }
  TreeS(TreeS* n)
  {
      this->data = n->data;
      this->left = NULL;
      this->right = NULL;
      size = 0;
  }
  
  
  
};