#include <iostream>
using namespace std;

class BadQueue{
    private:
        struct node{
            string name;
            int priority;
            node* next;
        };
        node* head;
    public:
        BadQueue(){
            head = NULL;
        }
        bool isEmpty(){
            return !head;
        }
        void enqueue(string n, int val)
        {
            node* nn = new node;
            nn->priority = val;
            nn->name = n;
            nn->next = head;
            if(isEmpty()){
                head = nn;
            }
            else if(val < head->priority){
                nn->next = head;
                head = nn;
            }
            else{
                node* temp = head;
                while(temp->next != NULL && temp->next->priority < val){
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
            cout<<n<<"("<<val<<")"<<" has been added to the queue."<<endl;
            cout<<" - "<<head->name<<" is at the front of the line."<<endl;
        }
        void deque()
        {
            node* temp = head;
            cout<<head->name<<" was removed from the queue."<<endl;
            head = head->next;
            delete(temp);
        }


};