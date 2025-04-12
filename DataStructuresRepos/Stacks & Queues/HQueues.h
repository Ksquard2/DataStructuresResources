#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
  
class Queue
{
  private:
    char queue[10];
    int rear = 0;
    int front = 0;
  public:
    bool isQEmpty()
    {
      return rear == front;
    }
    bool isQFull()
    {
      return ( front == (rear + 1) % 30 );
    }
    int getQSize()
    {
      if (rear >= front)
        return ( rear - front);
      else
        return 30 - front + rear;
    }
    char deque()
    {
      if(this->isQEmpty())
      {
        cout<<"Queue is empty"<<endl;
        return '0';
      }
      else
      {
        char temp = queue[front];
        front = (front+1)%30;
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
        queue[rear] = val;
        rear++;
      }
      
    }
    
      
          
    void printQueue()
    {
      for(int i = front;i < rear; i++)
      {
        cout<<queue[i]<<endl;
      }
    }
    
    
};