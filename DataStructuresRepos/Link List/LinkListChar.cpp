#include <iostream>
using namespace std;
class NodeC {
public:
    char data;
    NodeC* next;
    // Default constructor
    NodeC();
  
    // Parameterised Constructor
    NodeC(char data)
    {
        this->data = data;
        this->next = NULL;
    }
    NodeC(NodeC* n)
    {
        this->data = n->data;
        this->next = NULL;
    }
    void appendC(char data)
    {
      NodeC* temp = this;
      NodeC* newNode = new NodeC(data);
      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    
    }
void prettyPrint()
{
  NodeC* temp = this;
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




