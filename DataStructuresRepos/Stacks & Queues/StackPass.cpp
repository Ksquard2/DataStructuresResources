#include <iostream>
using namespace std;
struct node{
    char data;
    node* next;
};
class Register
{
  private:
    char queue[10];
    int rear;
    int front;
    node* BOQ;
    node* EOQ;
  public:
    Register(){
        rear,front = 0;
        BOQ = NULL;
        EOQ = NULL;
    }
    bool isQEmpty()
    {
      return rear == front;
    }
    bool isQFull()
    {
      return ( front == (rear + 1) % 10 );
    }
    int getQSize()
    {
      if (rear >= front)
        return ( rear - front);
      else
        return 10 - front + rear;
    }
    char pop()
    {
      if(this->isQEmpty())
      {
        cout<<"Queue is empty"<<endl;
        return '0';
      }
      else
      {
        if(BOQ){
            for(int i = front;i < 9;i++){
                swap(queue[i],queue[i+1]);
            }
            if(rear != 9){
                swap(queue[9],queue[0]);
                for(int i = 0;i < rear-1;i++){
                    swap(queue[i],queue[i+1]);
                }
            }
            queue[rear] = BOQ->data;
            BOQ = BOQ->next;
            return BOQ->data;
        }
        else{
            char temp = queue[front];
            front = (front+1)%10;
            return temp;
        }
        
      }
    }

    void pass(int val)
    {
      if(this->isQFull())
      {
        node* nn = new node; // Allocate memory for a new node
        nn->data = val;
        nn->next = NULL; // New node points to NULL

        if (!BOQ) {
            BOQ = nn; // Both BOQ and EOQ point to the new node
            EOQ = nn;
        } else {
            EOQ->next = nn; // Link the new node at the end
            EOQ = nn; // Update EOQ to the new node
        }
      }
      else
      {
        queue[rear] = val;
        rear++;
      }
      
    }
    
      
          
    void printRegister()
    {
      if(isQEmpty())
      for(int i = front;i < 10 ; i++)
      {
        cout<<queue[i]<<endl;
      }
      if(rear != 9){
        for(int i = 0; i < rear;i++){
            cout<<queue[i]<<endl;
        }
      }
      if(BOQ){
        node* temp = BOQ;
        while(temp){
            cout<<temp->data<<endl;
            BOQ = BOQ->next;
        }
      }
      
    }
    
    
};