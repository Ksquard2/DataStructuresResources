#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
int MAX_SIZE = 10;
class Register
{
  private:
    int queue[10];
    int rear;
    int front;
    node* TOS;

  public:
  Register(){
    rear = 0;
    front = 0;
    TOS = NULL;
  }
  bool isFull(){
    return rear == MAX_SIZE; 
  }
  bool isEmpty(){
    return rear == front;
  }
  void pass(int val){
    if(!isFull()){
      queue[rear] = val;
      rear++;
    }
    else{
      node* nn = new node;
      nn->data = val;
      nn->next = TOS;
      TOS = nn;
    }
  }
  void pop(){
    if(!isEmpty()){
      if(!TOS){
        front++;
      }
      else{

        for(int i = front;i < rear-1;i++){

          swap(queue[i],queue[i+1]);
        }
        queue[rear-1] = TOS->data;
        TOS = TOS->next;
      }
    }
  }
  void print(){
    cout<<"In Register: ";
    for(int i = front;i < rear;i++){
      if(i != rear-1){
        cout<<queue[i]<<", ";
      }
      else{
        cout<<queue[i];
      }
    }
    cout<<endl;
    cout<<"In Stack: ";
    node* temp = TOS;
    while(temp){
      if(temp->next){
        cout<<temp->data<<", ";
      }
      else{
        cout<<temp->data;
      }
      temp = temp->next;
    }
    cout<<endl;

  }
    
};