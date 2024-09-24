#include <iostream>
using namespace std;

class Stack
{

  public:
  int stack[30];
  int TOS = 0;
  int top = stack[TOS-1];

    bool isSEmpty()
    {
      return TOS == 0;
    }
    bool isSFull()
    {
      if(TOS >= 30)
      {
        return true;
      }
      else return false;
    }

    void push (int i) 
    {
      if(!this->isSFull())  
      {
        stack[TOS] = i;
        TOS++;
      } else 
      {
        cout << "Stak is full.  Push ignored.";
      }
    }
    int pop()
    {
      if(this->isSEmpty()){
        cout<<"Stack is empty"<<endl;
        return -1;
      }
      else 
      {
        int x = stack[TOS-1];
        TOS--;
        top = stack[TOS-1];
        return x;
      }
    }
    int getTop()
    {
      if(this->isSEmpty())
      {
        cout<<"Stack Is Empty"<<endl;
        return -1;
      }
      else
      {
        return top;
      }
      
    }
    int getSize()
    {
      if(this->isSEmpty())
        {
          cout<<"Stack Is Empty"<<endl;
          return -1;
        }
        else
        {
          return TOS;
        }
    }

    void printStack()
    {
      for(int i = TOS-1;i > -1; i--)
      {
        cout<<stack[i]<<endl;
      }
    }

  
};