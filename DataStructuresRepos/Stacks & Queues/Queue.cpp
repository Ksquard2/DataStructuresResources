#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
  
class Queue
{
  private:
    int queue[30];
    int rear = 0;
    int front = 0;
  public:
    int size(){
      return rear-front;
    }
    bool isQEmpty()
    {
      return size() == 0;
    }
    bool isQFull()
    {
      return size() == MAX_SIZE;
    }
    int deque()
    {
      if(this->isQEmpty())
      {
        cout<<"Queue is empty"<<endl;
        return -1;
      }
      else
      {
        int temp = queue[front%MAX_SIZE];
        front = (front+1);
        return temp;
      }
    }

    void enqueue(int val)
    {
      if(this->isQFull())
      {
        cout<<"Queue is full"<<endl;
      }
      else
      {
        queue[rear%MAX_SIZE] = val;
        rear++;
      }
      
    }
    void displayQueue(){
      if(!isQEmpty()){
        if(front%MAX_SIZE < rear% MAX_SIZE){
          for(int i = (front%MAX_SIZE);i < (rear%MAX_SIZE);i++){
            cout<<queue[i]<<" ";
          }
        }
        else{
          cout<<"hello"<<endl;
          for(int i = front%MAX_SIZE;i < MAX_SIZE;i++){
            cout<<queue[i]<<" ";
          }
          for(int i = 0;i < (rear%MAX_SIZE);i++){
            cout<<queue[i]<<" ";
          }
        
        }
        cout<<endl;
      }
      else{
        cout<<"Queue is empty";
      }
    }
    
    
    
    
};