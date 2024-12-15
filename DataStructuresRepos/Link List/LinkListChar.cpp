#include <iostream>
using namespace std;
class NodeC {
public:
    char data;
    NodeC* next;
    int length;

  bool operator==(NodeC* node)
  {
    NodeC* temp = this;
    NodeC* temp2 = node;
    if(temp->length != temp2->length)
    {
      return false;
    }
    while(temp != NULL)
    {
      if(temp->data != temp2->data)
      {
        return false;
      }
      temp = temp->next;
      temp2 = temp2->next;
    }
    return true;
  }
    // Default constructor
    NodeC(){
      this->next = NULL;
      length = 0;
    };
  
    // Parameterised Constructor
    NodeC(char data)
    {
        this->data = data;
        this->next = NULL;
        length = 1;
    }
    NodeC(NodeC* n)
    {
        this->data = n->data;
        this->next = NULL;
    }
    bool isEmpty(){
      return length == 0;
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
      length++;
    }
void DeleteAt(int pos)
{
  if(isEmpty())
  {
    cout<<"List is empty"<<endl;
  }
  else if(pos > length || pos < 0)
  {
    cout<<"Invalid position"<<endl;
  }
  else
  {
    NodeC *prev = NULL;
    NodeC *curr = this;

    while(pos != 0)
    {
      prev = curr;
      curr = curr->next;
      pos--;
    }
    if(curr->next == NULL)
    {
      prev->next = NULL;
    }
    else
    {
      prev->next = curr->next;
      curr->next = nullptr;
    }
    length--;
  }
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




