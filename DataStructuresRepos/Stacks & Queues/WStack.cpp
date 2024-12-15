#include <iostream>
using namespace std;

class Stack
{
    public:
        struct StackP
        {
            int value;
            StackP* next;
        };
        StackP* TOS;
        int size;
        Stack(){
            size = 0;
            TOS = NULL;
        }
        bool isEmpty(){
            return (size == 0 && TOS == NULL);
        }

        void push(int data){
            if(isEmpty())
            {
                TOS->value = data;
            }
            else
            {
                StackP* newNode = new StackP();
                newNode->value = data;
                newNode->next = TOS;
                TOS = newNode;
            }
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else
            {
                TOS = TOS->next;
            }
        }

};