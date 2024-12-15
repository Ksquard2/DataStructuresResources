#include <iostream>
#include <math.h>
#include "MinHeapP.h"
#include <map>
using namespace std;



class PQueue{
  public:
    MinHeapP h;
    map<int, string> people;
    int index;
    PQueue() : h(8){
        index = 1;
    }
    bool isFull(){
      return h.IsFull();
    }
    bool isEmpty(){
      return h.IsEmpty();
    }
    void Enqueue(int priority, string name){
      if(people.find(priority) == people.end()){
        cout<<name<<" has been added to this list"<<endl;
        h.insert(priority);
        people[priority] = name;
        cout<<people[h.getArray()[1]]<<" is now in the front of the line."<<endl;
    
      }
      else{
        cout<<"Priority is already listed"<<endl;
      }
    }
    void Dequeue(){
        string meep = people[h.arr[index]];
        cout<<meep<<" has just left the line."<<endl;

        h.DeleteMin();
        index++;
        // string gord = people[h.arr[index]];
        // cout<<gord<<" is now in the front of the line."<<endl;
    }

};
