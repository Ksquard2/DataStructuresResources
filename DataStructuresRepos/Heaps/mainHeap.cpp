#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
// #include "MinHeapP.h"

#include "MaxHeapP.h"
#include "PrioirityQueue.cpp"

using namespace std;
int capacity  = 8;
void printArray(int arr[], int len){
  for(int i = 1;i < 8;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main() 
{    
  PQueue p;
  int arr[7] = {4,3,8,2,5,7,6};
 
  
  
  string meep[7] = {"Barry","Iris","Zoom","Wally","Eobard","Goku","Vegeta"};
  for(int i = 0;i < 7;i++)
  {
    p.Enqueue(arr[i],meep[i]);
  } 
  p.Dequeue();
  p.Dequeue();
   // MaxHeap h(arr,7,8);
  // h.printHeapLin();
  // cout<<endl<<endl;
  // h.printHeap();
  // MinHeapP h(arr,7,8);
  // h.DeleteMin();
  // h.printHeap();
  // int arr[8] = {-1,4,3,12,9,5,7,6};
  // heapSort(arr,8);
  // printArray(arr,8);
};
  



