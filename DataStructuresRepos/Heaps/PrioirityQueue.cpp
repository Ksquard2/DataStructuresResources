#include <iostream>
#include <math.h>
#include "MaxHeapP.h"
#include <map>
using namespace std;



class PQueue{
  public:
    MaxHeapP h;
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
        
        h.insert(priority);
        people[priority] = name;
        cout<<people[h.getArray()[1]]<<" is in the front of the line."<<endl;
        cout<<" - "<<name<<"("<<priority<<") has been added to the list"<<endl;
    
      }
      else{
        cout<<"Priority is already listed"<<endl;
      }
    }
    void Dequeue(){
        string meep = people[h.arr[1]];
        cout<<meep<<" has just left the line."<<endl;

        h.DeleteMax(1);
        index++;
        // string gord = people[h.arr[index]];
        // cout<<gord<<" is now in the front of the line."<<endl;
    }

};
