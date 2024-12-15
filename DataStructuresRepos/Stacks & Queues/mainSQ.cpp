#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include "StackFS.cpp"
#include "StackF.cpp"
#include "DLLQueues.cpp"
#include "SLLQueues.cpp"
#include "SLLQueueStr.cpp"
#include <string>

using namespace std;
void mp3(){
SLLQueueS* playlist = new SLLQueueS();
 string a = "c";
 string input;
 string carry;
 int choice;
 while(a == "c"){
  cout<<"Press 1 to play a song, press 2 to add a song to the queue, press 3 to move to the next song: ";
  cin>>choice;
  switch(choice){
    case 1:
      cout<<"Please enter a song: ";
      cin>>input;
      if(playlist->isEmpty()){
        playlist->Enqueue(input);
      }
      else{
        playlist->BOQ->data = input;
      }
      cout<<"You are currently listening to "<<playlist->getFront()<<endl;
      cout<<"Press c to continue playing music: ";
      cin>>a;
      break;
    case 2:
      cout<<"Please enter a song: ";
      cin>>input;
      playlist->Enqueue(input);
      cout<<"You are currently listening to "<<playlist->getFront()<<endl;
      cout<<"Press c to continue playing music: ";
      cin>>a;
      break;
    case 3:
      playlist->Deque();
      cout<<"You are currently listening to "<<playlist->getFront()<<endl;
      cout<<"Press c to continue playing music: ";
      cin>>a;
      break;
  }
 }
}
void SearchBar(){
 
 StackFS* curr = new StackFS();
 StackFS* history = new StackFS();
 string a = "c";
 string input;
 string carry;
 int choice;
 while(a == "c"){
  cout<<"Press 1 to search, press 2 to go back, press 3 to go forward: ";
  cin>>choice;
  switch(choice){
    case 1:
      cout<<"Please type in a website: ";
      cin>>input;
      curr->push(input);
      cout<<"You are currently at "<<curr->top()<<endl;
      cout<<"Press c to continue using the browser: ";
      cin>>a;
      break;
    case 2:
      if(curr->getSize() < 2){
        cout<<"No prior hisotry"<<endl;
      }
      else{
        carry = curr->pop();
        history->push(carry);
        cout<<"You are currently at "<<curr->top()<<endl;
      }
      cout<<"Press c to continue using the browser: ";
      cin>>a;
      break;
    case 3:
      if(history->isEmpty())
      {
        cout<<"No backlogged sites."<<endl;
      }
      else
      {
        carry = history->pop();
        curr->push(carry);
        cout<<"Your currently at "<<carry<<endl;
      }
      cout<<"Press c to continue using the browser: ";
      cin>>a;
      break;
  }
 }
}
int main() 
{
SearchBar();


}