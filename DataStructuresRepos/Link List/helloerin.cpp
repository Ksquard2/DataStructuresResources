#include <iostream>
#include <fstream>
using namespace std;
class Stack{
    private:// each node stores one char and a pointer to the next node
    struct node{
        char data; 
        node *next; 
    };
    node *head; //points to the top of stack
    public:// when the stack starts it should be empty
    Stack(){
        head = NULL;
    }
    
      void addfront(char data);//adds a node to the front of the stack
      char removefront();///rmeove something from the front
      void display();///print everything in the stack
      bool isEmpty();//checks ti make sure there si no elements
      char top(){
        if(head != NULL){
            return head->data; 
        }
        else{
            return '0'; 
        }
      }
};
bool Stack::isEmpty(){
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
    bool balance(string symbols){
        Stack s; 
        for(int i = 0; i< symbols.length(); i++){
            if( symbols[i] == '[' || symbols[i]== '{'|| symbols[i]== '('){
                s.addfront(symbols[i]);
            }
            else if(!s.isEmpty()){
                if(symbols[i] == '}'){
                    if(s.top()== '{'){
                        s.removefront();
                    }
                    else{
                        return false;
                    }
                }
                else if(symbols[i]== ')'){
                    if(s.top()== '('){
                        s.removefront();
                    }else{
                        return false; 
                    }
                }
            
                else if(symbols[i]==']'){
                    if(s.top()== '['){
                        s.removefront();
                    }else{
                        return false; 
                    }
                }
        
                else if(symbols[i] == '}'){
                    if(s.top() =='{'){
                        s.removefront();
                    }else{
                        return false; 
                    }
                }
            }
            else{
                return false;
            }

        }
        return s.isEmpty();
    }
    int main(int argc, char *argv[]){///make sure the user actually typed the filename

    // if not, show the program name and stop int argc, char *argv[]

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
           {
                if( balance(fileinfo)){
                    cout<< "legal"<<endl;
                }else{
                    cout<< "Error"<<endl;
                }
            }
    }/// adds a blank after
    return 0; 
}

