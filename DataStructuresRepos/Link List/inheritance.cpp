#include <iostream>
using namespace std;

class LinkList{
    protected:
        struct node{
            int data;
            node* next;
        };
        node* head;
        int size;
    public:
        LinkList(){
            head = NULL;
            size = 0;
        }
        bool isEmpty(){
            return head == NULL;
        }
        void addNode(int val, int pos)  {//this is to add a node at a specific position
            node* nn = new node;
            nn->data = val;
            if(pos > size || pos < 0){
                cout<<"nah";
                return;
            }
            else if(pos == 0){
                nn->next = head;
                head = nn;
            }
            else{
                node* temp = head;
                while(pos != 1){
                    temp = temp->next;
                    pos-- ;
                }
                nn->next = temp->next;
                temp->next = nn;
            }
            size++;
        }

        void removeNode(int pos) {
            if(isEmpty() || pos < 0 || pos >= size){
                cout<<"nah";
                return;
            }
            else if(pos == 0){
                node* toDelete = head;
                head = head->next;
                delete(toDelete);
                size--;
                return;
            }
            else{
                node* curr = head;
                node* prev = NULL;
                int steps = pos;
                while(steps > 0){
                    prev = curr;
                    curr = curr->next;
                    steps--;
                }
                prev->next = curr->next;
                size--;
                delete(curr);
            }
            
        }
        void display(){
            node* temp = head;
            while(temp){
                cout<<temp->data;
                if(temp->next != NULL){
                    cout<<"->";
                }
                temp = temp->next;
            }
            cout<<endl;
        }
};

class Stack: public LinkList{
    public:
    Stack() : LinkList(){}
    void addNode(int val) {
        node* nn = new node;
        nn->data = val;
        nn->next = head;
        head = nn;
    }
    void removeNode() {
        if(!isEmpty()){
            node* temp = head;
            head = head->next;
            delete(temp);
        }
        else{
            cout<<"nah";
        }
    }
};

class Queue: public LinkList{
    private:
    node* tail;
    public:
    Queue(): LinkList(){
        tail = NULL;
    }
    void addNode(int val) {
        node* nn = new node;
        nn->data = val;
        nn->next = NULL;
        if(isEmpty()){
            head = tail = nn;
        }
        else{
            tail->next = nn;
            tail = nn;
        }
    }
    void removeNode() {
        if(!isEmpty()){
            node* temp = head;
            head = head->next;
            delete(temp);
        }
        else{
            cout<<"nah";
        }
    }
};

int main(){
    cout << "===== TESTING LINKED LIST WITH POS INSERT =====" << endl;
    LinkList list;
    list.addNode(10, 0);   // insert at head
    list.addNode(20, 1);   // insert at end
    list.addNode(15, 1);   // insert in middle
    list.display();        // Expected: [ 10 15 20 ]

    cout << "Removing index 1..." << endl;
    list.removeNode(1);
    list.display();        // Expected: [ 10 20 ]

    cout << "\n===== TESTING STACK (push/pop) =====" << endl;
    Stack s;
    s.addNode(5);
    s.addNode(10);
    s.addNode(15);
    s.display();           // Expected stack (top first): [ 15 10 5 ]

    cout << "Stack pop..." << endl;
    s.removeNode();
    s.display();           // Expected: [ 10 5 ]

    cout << "\n===== TESTING QUEUE (enqueue/dequeue) =====" << endl;
    Queue q;
    q.addNode(1);
    q.addNode(2);
    q.addNode(3);
    q.display();           // Expected queue (front first): [ 1 2 3 ]

    cout << "Queue dequeue..." << endl;
    q.removeNode();
    q.display();           // Expected: [ 2 3 ]

    cout << "\n===== ALL TESTS COMPLETE =====" << endl;
}