#include <iostream>
#include <fstream>
using namespace std;
class Stack{
    private:    // each node stores one char and a pointer to the next node
    struct node{
        char data; 
        node *next; 
    };
    node *head;// points to the top of stack
    public:// when the stack starts it should be empty
    Stack()
    {
        head = NULL;
    }
      void addfront(char data);//adds a node to the front of the stack
      char removefront();///rmeove something from the front
      void display();///print everything in the stack
      bool isEmpty();//checks ti make sure there si no elements
};
bool Stack::isEmpty()
{
    return head == nullptr; 
}///returns true if emepty
void Stack::addfront(char data){
    node *temp = new node; ///creates a new node
    temp->data = data;  // stores the char
    temp->next = head; // link it to the current top
    head = temp; ///updates the top/head
}

char Stack::removefront(){
    if(!isEmpty()){ //only do this if there's something to remove
        node * temp = head; ///sets our temp equal to the head
        char c = temp->data; //sve the char in it
        head = head->next; //move the top down 
        delete(temp); /// delete the old head
        return c; ///return the removed char
    }
    return 0; ///if it waS empty return 0
}
void Stack::display(){
    node *temp = head; 
    while(temp !=NULL){ ///walk through the stack
        cout<< temp->data<< endl; ///prints each char
        temp = temp->next; ///move to the next one
    }
}
int main(int argc, char *argv[]){   ///make sure the user actually typed the filename
    // if not, show the program name and stop
        if(argc < 2){
        cout<< argv[0]<< endl; 
        return 1; 
    }
    ///try to open the file they gave us
    ifstream inputfile(argv[1]);
     if(!inputfile){
        cout<< " ERROR..."<< endl; 
        return 1;
    }/// if the file cannot open, show an  error message
    string fileinfo; 
    Stack s; 
    /// read the file one line at a time
    while(getline(inputfile, fileinfo))
    {
        ///adds a char to the front of the stack
        //this should reverse the chars since it's LIFO
        for(int i = 0; i < fileinfo.length(); i++){
            s.addfront(fileinfo[i]);

        }
        ////remove from the front and prints everything in the stack 
        while(!s.isEmpty()){
            char removed = s.removefront();
            cout<< removed << endl; 
        }
        cout<<endl;
    }/// adds a blank after
    return 0; 
}
