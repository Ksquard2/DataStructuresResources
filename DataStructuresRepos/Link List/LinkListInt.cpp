#include <iostream>
using namespace std;
class NodeI {
public:
  int data;
  NodeI* next;
  int length;
  // Default constructor
  NodeI()
  {
      length = 0;
      next = NULL;
  }

  // Parameterised Constructor
  NodeI(int data)
  {
      this->data = data;
      length = 1;
      this->next = NULL;
  }

  bool isEmpty()
  {
    return length == 0;
  }
  int len(){
    return length;
  }
  void append(int val)
  {
    if(isEmpty()){
      this->data = val;
    }
    else{
      NodeI* temp = this;
      NodeI* newNode = new NodeI(val);
      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newNode;
      
    }
    length++;
  }
  NodeI(int *arr, int len)
  {
    // this->data = arr[0];
    for(int i = 0; i < len; i++){
      append(arr[i]);
    }
    length = len;
  } 
  void prettyPrint()
  {
    NodeI* temp = this;
      while(temp != NULL)
      {
        if(temp->next != NULL)
        {
          cout<<temp->data<<"->";
        }
        else{
          cout<<temp->data;
        } 
        
        temp = temp->next;
      }
      cout<<endl;
  
  }

void insertAtHelper(NodeI* node, int data, int pos)
{
  if(pos == 0)
  {
    node->data = data;
   
  }
  else if(pos == 1)
  {
    NodeI* newNode = new NodeI(data);
    newNode->next = node->next;
    node->next = newNode;
  }
  else
  {
    insertAtHelper(node->next, data, pos-1);
  }
}
  void insertAt(int data, int pos)
  {
    if(pos > length){
      cout<<"Invalid position"<<endl;
    }
    else{
      NodeI* temp = this;
      insertAtHelper(temp, data, pos);
      length++;
    }
  }
int posOf(int d){
  if(isEmpty()){
    return -1;
  }
  NodeI* temp = this;
  int pos = 0;
  while(temp != NULL){
    if(temp->data == d)
      return pos;
    temp = temp->next;
    pos++;
  }
  return -1;
}

void DeleteVal(int val)
{
    if(isEmpty())
    {
      cout<<"List is empty"<<endl;
    }
    else
    {
      NodeI *prev = NULL;
      NodeI *curr = this;

      while(curr->next != NULL && curr->data != val)
      {
        prev = curr;
        curr = curr->next;
      }
      if(curr->next != nullptr)
      {
        prev->next = curr->next;
        curr->next = nullptr;
        length--;
      }
      else
      {
        cout<<"Not in the list"<<endl;
      }
    }
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
    NodeI *prev = NULL;
    NodeI *curr = this;

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
int elementAt(int i)
{
  if(isEmpty())
  {
    return -1;
  }
  NodeI* temp = this;
  while(temp != NULL && i > 0)
  {
    temp = temp->next;
    i--;
  }
  if(temp == NULL) return -1;
    
  else return temp->data;
}

bool IsIn(int d)
{
  if(isEmpty())
  {
    return false;
  }
  NodeI* temp = this;
  while(temp->next != NULL)
  {
    if(temp->data == d) 
    {
      cout<<temp->data<<endl;
      return true;
    }
    temp = temp->next;
  }
  return false;
}

};
 






