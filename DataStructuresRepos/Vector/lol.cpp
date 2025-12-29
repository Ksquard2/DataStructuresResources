#include <iostream>
#include <fstream>
using namespace std;

class list{
    private:
        struct node{
            int nums; 
            node *next;
        };
        node *head;
    public:
        list(){
            head = NULL;
        }
        ~list(){
            head = NULL;
        }
        void append(int val);
        void insert(int val);
        void display();
        void deletenode();
};

void list::append(int val){
    node *temp = new node; 
    node *iter = head; 
    temp->next = nullptr; 
    if(head == NULL){
        head = temp; 
    }
    else{
    temp->nums = val; 
        while(iter->next !=nullptr){
        iter = iter->next;
    
        
    }
    iter->next = temp; 
}
}

void list::insert(int val){
    node *temp = new node;
    temp->next = nullptr; 
    temp->nums = val; 
    if(head == NULL){
        head = temp; 
    }
    else{
        node *iter = head;
        while(iter->next !=nullptr){
            if(iter->next->nums > temp->nums){
                temp->next = iter->next;
                iter->next =temp;
            }
            iter = iter->next; 
        }
    
}
}
void list::display(){
    node *temp = head; 
    while(temp != nullptr){
        cout<< temp->nums<< " "; 
        temp = temp->next; 
    }
    cout<<endl;
};

void list::deletenode(){
    node *temp = head; 
    head= head->next; 
    delete(temp);
};

int main(){
    int val; 
    list l;
    string fname;
    cout<<"What is your file name: ";
    cin>>fname;
    ifstream inputfile("hello.txt");
    if(!inputfile){
        cout<< "Error..."<< endl;
        return 1; 
    }
    while(inputfile>>val){
        l.append(val);
    }
    // l.append(3);
    // l.append(4);
    // l.append(5);
    // l.insert(6);
    // l.append(7);
    l.display();
    l.deletenode(); 
    l.deletenode();
    l.display();
    
    return 0; 
}