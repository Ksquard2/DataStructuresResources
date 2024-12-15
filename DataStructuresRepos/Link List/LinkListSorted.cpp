#include <iostream>
using namespace std;

class Sorted{
    public:
    struct sort
    {
      int data;
      sort* next;
    };
    sort* head;
    int size;
    Sorted(){
        head = NULL;
        size = 0;
    }
    Sorted(int val){
        head->data = val;
        size = 1;
    }
    bool isEmpty(){
        return size == 0;
    }
    void insert(int val)
    {
        sort* nn;
        nn->data = val;
        if(isEmpty())
        {
            head = nn;
        }
        else{
            if(nn->data < head->data)
            {
                nn->next = head;
                head = nn;
            }
            else
            {
                sort* temp = head;
                while(temp->next != NULL && temp->next->data < val){
                    temp = temp->next;
                }
                if(temp->next != NULL){
                    nn->next = temp->next;
                    temp->next = nn;
                }
                else{
                    temp->next = nn;
                }
            }
        }
        
    }
};