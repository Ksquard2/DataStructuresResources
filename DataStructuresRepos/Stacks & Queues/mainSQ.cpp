#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include "StackFS.cpp"
#include "StackF.cpp"
#include "DLLQueues.cpp"
#include "SLLQueues.cpp"
#include "SLLQueueStr.cpp"
#include "StackPass.cpp"
#include "BadQueue.h"
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
// void mp3(){
// SLLQueueS* playlist = new SLLQueueS();
//  string a = "c";
//  string input;
//  string carry;
//  int choice;
//  while(a == "c"){
//   cout<<"Press 1 to play a song, press 2 to add a song to the queue, press 3 to move to the next song: ";
//   cin>>choice;
//   switch(choice){
//     case 1:
//       cout<<"Please enter a song: ";
//       cin>>input;
//       if(playlist->isEmpty()){
//         playlist->Enqueue(input);
//       }
//       else{
//         playlist->BOQ->data = input;
//       }
//       cout<<"You are currently listening to "<<playlist->getFront()<<endl;
//       cout<<"Press c to continue playing music: ";
//       cin>>a;
//       break;
//     case 2:
//       cout<<"Please enter a song: ";
//       cin>>input;
//       playlist->Enqueue(input);
//       cout<<"You are currently listening to "<<playlist->getFront()<<endl;
//       cout<<"Press c to continue playing music: ";
//       cin>>a;
//       break;
//     case 3:
//       playlist->Deque();
//       cout<<"You are currently listening to "<<playlist->getFront()<<endl;
//       cout<<"Press c to continue playing music: ";
//       cin>>a;
//       break;
//   }
//  }
// }
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
      if(!curr->getSize()){
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

// int postfix(string post){
//     StackF stk;
//     int a;
//     int b;
//     for(int i = 0;i < post.length();i++)
//     {
//       cout<<stk.top()<<endl;
//         if(post[i] == '*'){
//             a = stk.pop();
//             b = stk.pop();
//             int complete = a*b;
//             stk.push(complete);
//         }
//         else if(post[i] == '+'){
//             a = stk.pop();
//             b = stk.pop();
//             int complete = a+b;
//             stk.push(complete);
//         }
//         else if(post[i] == '/'){
//             a = stk.pop();
//             b = stk.pop();
//             int complete = b/a;
//             stk.push(complete);
            
//         }
//         else if(post[i] == '-'){

//             a = stk.pop();
//             b = stk.pop();
//             int complete = b-a;
//             stk.push(complete);
//         }
//         else if(post[i] == '='){
//           return stk.top();
//         }
//         else
//         {
//           stk.push(cti(post[i]));
//         }
//     }
// }

int main() 
{
  BadQueue p;
  int arr[7] = {4,3,8,2,5,7,6};
 
  
  
  string meep[7] = {"Barry","Iris","Zoom","Wally","Eobard","Goku","Vegeta"};
  for(int i = 0;i < 7;i++)
  {
    p.enqueue(meep[i],arr[i]);
  } 
  p.deque();
  p.deque();
  // for(int i = 0;i < 20;i++){
  //   char random_char = 'a'+ rand() % 26; 
  //   r.pass(random_char);
  // }
//  r.printRegister();
//   int x =10;
// int arr[5]= {1,2,3,4,5};

// for(int i = 0;i < 5;i++){
//   for(int t = 0;t< i;t++){
//       if(!t){
//         cout<<setw(x)<<arr[t];
//       }
//       else{
//         cout<<setw(x/2)<<arr[t];
//       }
//   }
//   x--;
//     cout<<endl;
// }
  // string post = "98+12*/=";
  // StackF stk;
  // cout<<postfix(post);

}