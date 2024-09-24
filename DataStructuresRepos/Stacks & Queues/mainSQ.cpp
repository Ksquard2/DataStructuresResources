#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
#include "StackFS.cpp"
#include "StackF.cpp"
#include "DLLQueues.cpp"

using namespace std;

int main() {
  DLLQueue* Q = new DLLQueue();
  Q->Enqueue(1);
  Q->Enqueue(2);
  Q->Enqueue(3);
  Q->Enqueue(4);
  Q->Enqueue(5);
  cout<<"Queue size: "<<Q->size()<<endl;
  Q->print();
  Q->Deque();
  cout<<"Queue size: "<<Q->size()<<endl;
  Q->print();
  return 0;
}