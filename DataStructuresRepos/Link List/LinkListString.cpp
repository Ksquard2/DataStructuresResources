#include <iostream>
#include <string>
using namespace std;
class NodeS {
public:
    string data;
    NodeS* next;
    // Default constructor
    NodeS();
  
    // Parameterised Constructor
    NodeS(string data)
    {
        this->data = data;
        this->next = NULL;
    }
bool IsIn(string str)
{
  NodeS* temp = this;
  while(temp->next != NULL){
    if(temp->data == str)
      return true;
  }
  return false;
}
    void appendC(string data)
    {
      NodeS* temp = this;
      NodeS* newNode = new NodeS(data);
      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    
    }
void prettyPrint()
{

  NodeS* temp = this;
    while(temp != NULL)
    {
      if(temp->next != NULL)
      {
        cout<<temp->data<<"->";
      }
      else cout<<temp->data;
      temp = temp->next;
    }
    cout<<endl;

}
};




