#include <iostream>
#include <string>

using namespace std;
class StackFS 
{
public:
    struct StackP
    {
      string data;
      StackP* next;
    };
    StackP* TOS;
    int size;
    

    // Default constructor
    StackFS()
    {
        TOS = NULL;
        size = 0;
    }
    bool isEmpty()
    {
        return (size == 0 && TOS == NULL);
    }
    void push(string data)
    {
      if(isEmpty()){
        StackP* newNode = new StackP();
        newNode->data = data;
        TOS = newNode;
      }
      else{
        StackP* newNode = new StackP();
        newNode->data = data;
        newNode->next = TOS;
        TOS = newNode;  
      }
        size++;
    }
    string pop()
    {
        StackP* temp = TOS;
        if (!isEmpty())
        {
            TOS = TOS->next;
            size--;
            return temp->data;
        }
        else
        {
          cout << "Stack is empty" << endl;
          return "1";
        }
        
    }
    string top()
    {
      if(!isEmpty()){
        return TOS->data;
      }
      else
      {
        cout<<"Stack Is Empty"<<endl;
        return "1";
      }
    }
    int getSize()
    {
      return size;
    }
    void printStack()
    {
      StackP* temp = TOS;
      int i = 0;
      while(temp != NULL)
      {
        i++;
        cout<<temp->data<<endl;
        if(i != size)
        {
          cout<<"|"<<endl;
          cout<<"V"<<endl;
        }
        temp = temp->next;
      }
    }
  
 

};




