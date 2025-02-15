#include <iostream>
using namespace std;

class Sorted{
    public:
    struct sort
    {
      string name;
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
    void insert(int val,string n)
    {
        sort* nn;
        nn->data = val;
        nn->name = n;
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
    void DeleteVal(int val) //delete items
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            sort *prev = NULL;
            sort *curr = head;
            while(curr->next != NULL && curr->data != val)
            {
                prev = curr;
                curr = curr->next;
            }
            if(curr->next != nullptr)
            {
                prev->next = curr->next;
                curr->next = nullptr;
                size--;
            }
            else
            {
                cout<<"Not in the list"<<endl;
            }
        }
    }
};