#include <iostream>
using namespace std;
  struct Node{
    int data;
    Node* next;
  };
class NodeI {

public:
  Node* head =  new Node;
  int length;
  // Default constructor
  NodeI()
  {
      length = 0;
      head = NULL;
  }

  bool operator==(NodeI node)
  {
    Node* temp = head;
    NodeI temp2 = node;
    if(length != temp2.length)
    {
      return false;
    }
    while(temp && temp2.head)
    {
      if(temp->data != temp2.head->data)
      {
        return false;
      }
      temp= temp->next;
      temp2.head = temp2.head->next;
    }
    return true;
  }

  // Parameterised Constructor & put item
  NodeI(int data)
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
  void append(int val)
  {   
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    if(isEmpty()){
      head = newNode;
    }
    else{
      Node* temp = head;
      while(temp->next)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
    length++;
  }
  NodeI(int arr[], int len)//overloaded constructor
  {
    for(int i = 0; i < len; i++)
    {
      append(arr[i]);
    }    
    length = len;
    head = head->next;
  } 

  void prettyPrint()
  {
    Node* temp = head;
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

  void insertAt(int val, int pos)
  {
    Node* nn = new Node;
    nn->data = val;
    if(pos > length){
      cout<<"Invalid position"<<endl;
    }
    else if(pos == 0 && !head){
      head = nn;
      length++;
    }
    else if(!pos && head){
      nn->next = head;
      head = nn;
      length++;
    }
    else{
      Node* temp = head;
      for(int i = 0;i < pos;i++)
      {
        if(!temp){
          return;
        }
        temp = temp->next;
      }
      nn->next = temp->next;
      temp->next = nn;
  }
}

int posOf(int d){
  if(isEmpty())
  {
    return -1;
  }
  Node* temp = head;
  int pos = 0;
  while(temp != NULL){
    if(temp->data == d)
      return pos;
    temp = temp->next;
    pos++;
  }
  return -1;
}

void DeleteVal(int val) //delete items
{
    if(isEmpty())
    {
      cout<<"List is empty"<<endl;
    }
    else
    {
      Node *prev = NULL;
      Node *curr = head;
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
    Node *prev = NULL;
    Node *curr = head;

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
int elementAt(int i) //get item
{
  if(isEmpty())
  {
    return -1;
  }
  if(i > length-1){
    return -1;
  }
  Node* temp = head;
  while(i > 0)
  {
    temp = temp->next;
    i--;
  }
  return temp->data;
  
}

void deleteAll(int val){
  if(head == NULL){//checks if list is empty
    return;
  }
  while(head != NULL&&head->data == val){//checks if val is in th beginning
    head = head->next;
  }
  if(head == NULL){//if list is all just the value
    return;
  }
  Node* curr = head;
  Node* prev = head;
  
  while(curr != NULL){
    if(curr->data == val){
      while(curr->next != NULL && curr->next->data == val){//if the value is consecutive
        curr = curr->next;
      }
      prev->next = curr->next;//removes the node or set of nodes that are the value
      curr->next = NULL;
      curr = prev->next;
    }
    else{
      prev = curr;//moves forward if we dont find anything
      curr = curr->next;
    }
  }
}

bool IsIn(int d)
{
  if(isEmpty())
  {
    return false;
  }
  Node* temp = head;
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
NodeI rotate(int n)
{
  if(isEmpty() || !head->next){
    return *this;
  }
  Node* Last = head;
  int i = (length - (n%(length)));
  while (Last->next != nullptr) 
  {
    Last = Last->next;
  }
  
  Last->next = head;
  while (i > 0)
  {
    head = head->next;
    Last = Last->next;
    i--;
  }
  Last->next = nullptr;
  // prettyPrint();
  return *this;
}
void insertList(NodeI s2, int k) 
{
  Node* temp1 = head;
  Node* temp2 = s2.head;
  if (temp1 == nullptr || temp2 == nullptr) 
  {
    return;
  }
  for (int i = 0; i < k - 1; i++) 
  {

    temp1 = temp1->next;
  }
  while  (temp2->next != nullptr) 
  {
    temp2 = temp2->next;
  }

  temp2->next = temp1->next;
  temp1->next = s2.head;
  prettyPrint();
}
// void deleteAll(int val)
// {
//   Node* temp = head;
//   Node* prev = NULL;
//   while(temp->data == val){
//     head = temp->next;
//     temp = temp->next;
//   }
//   while(temp != NULL){
//     if(temp->data == val){
//       prev->next = temp->next;
//       temp = temp->next;
//       prev->next = NULL;
//     }
//     else
//     {
//       prev = temp;
//       temp = temp->next;
//     }
//   }
// }
NodeI reverseList(){

    Node* curr = head;
    NodeI prev;
    Node* next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev.head;
        prev.head = curr;
        curr = next;
    }
    return prev;
}


};
 






