#include <iostream>
using namespace std;

class DLLQueue{
public:
  struct DLLQ
  {
    int val;
    DLLQ* prev;
    DLLQ* next;
  };

  DLLQ* Rear;
  DLLQ* Front;
  int Q_size;
  DLLQueue()
  {
    Rear = NULL;
    Front = NULL;
    Q_size = 0;
  }
  bool isEmpty()
  {
    return Rear == NULL && Front == NULL;
  }
  
  void Enqueue(int i)
  {
    DLLQ* curr = new DLLQ();
    curr->val = i;
    if(isEmpty())
    {
      Front = curr;
      Rear = curr;
    }
    else
    {
      Rear->next = curr;
      curr->prev = Rear;
      Rear = Rear->next;
    }
    Q_size++;
  }
  int size()
  {
    return Q_size;
  }
  void print()
  {
    DLLQ* Marker = Front;
    while(Marker != NULL)
    {
      cout<<Marker->val<<endl;
      Marker = Marker->next;
    }
    cout<<endl;
  }
  int Deque()
  {
    if(isEmpty()){
      return -1;
    }
    else 
    {
      int item = Front->val;
      Front = Front->next;
      Q_size--;
      return item;
    }
    
  }
};