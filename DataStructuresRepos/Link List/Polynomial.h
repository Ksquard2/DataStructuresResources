#include <iostream>
using namespace std;
class NodePoly {
public:
  int coe; 
  int exp;
  NodePoly* next;

  // Default constructor
  NodePoly()
  {
      coe = 0;
      exp = 0;
      next = NULL;
  }

  // Parameterised Constructor
  NodePoly(int c, int e)
  {
      this->exp = e;
      this->coe = c;
      this->next = NULL;
  }
  void append(NodePoly* sub)
  {
    NodePoly* temp = this;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = sub;
  }
  void prettyPrint()
  {
    cout<<"Answer: ";
    NodePoly* temp = this;
      while(temp != NULL)
      {
        if(temp->next == NULL)
        {
          if(temp->exp > 1)
          {
            cout << temp->coe << "x^" << temp->exp;
          }
          else if(temp->exp == 0)
          {
            cout << temp->coe;
          }
          else if(temp->exp == 1)
          {
            cout << temp->coe<<"x";
          }
        }
        else if(temp->next->coe > 0 && temp->exp > 1)
        {
          
          cout << temp->coe << "x^" << temp->exp<< "+" ;
        }
        else if(temp->next->coe < 0 && temp->exp > 1)
        {
          cout <<temp->coe << "x^" << temp->exp;
        }
        else if(temp->next->coe > 0 && temp->exp == 0)
        {
          cout << temp->coe<< "+" ;
        }
        else if(temp->next->coe < 0 && temp->exp == 0)
        {
          cout<< temp->coe;
        }
        else if(temp->next->coe > 0 && temp->exp == 1)
        {
          cout << temp->coe<<"x+";
        }
        else if(temp->next->coe < 0 && temp->exp == 1)
        {
          cout<< temp->coe<<"x";
        } 
        temp = temp->next;
      }
      cout<<endl;
  }
 

};




