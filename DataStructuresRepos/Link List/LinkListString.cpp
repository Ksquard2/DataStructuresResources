#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;
  struct NodeS{
    string data;
    NodeS* next;
  };


class SList {

public:
  NodeS* head =  new NodeS;
  int length;
  // Default constructor
  SList()
  {
      length = 0;
      head = NULL;
  }

 

  // Parameterised Constructor & put item
  SList(string data)
  {
      head->data = data;
      length = 1;
      head->next = NULL;
  }
  bool isEmpty(){
    return head == NULL;
  }
  int len(){
    return length;
  }
  void append(string val)
  {   
    NodeS* newNode = new NodeS;
    newNode->data = val;
    newNode->next = NULL;
    if(isEmpty()){
      head = newNode;
    }
    else{
      NodeS* temp = head;
      while(temp->next)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    length++;
  }

  void prettyPrint()
  {
    NodeS* temp = head;
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
};


 






