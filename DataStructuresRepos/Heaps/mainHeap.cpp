#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
// #include "MinHeapP.h"

#include "PrioirityQueue.cpp"
using namespace std;
int capacity  = 8;
void printArray(int arr[], int len){
  for(int i = 1;i < 8;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void buildHeap(int arr[], int len){

  MaxHeap h(8);
  for (int i = 1;i < len; i++)
  {
    h.insert(arr[i]);
  }
  for(int i = 1;i < len;i++){
    arr[i] = h.arr[i];
  }
}
void heapify(int arr[],int range,int index = 1){
  if((index * 2) + 1 < range){
    if(arr[index * 2] < arr[(index * 2) + 1]){
      if(arr[index] < arr[(index * 2) + 1]){
        swap(arr[index],arr[(index * 2) + 1]);
        index = index * 2;
        index++;
        heapify(arr,range,index);
      }
    }
    else{
      if(arr[index] < arr[index * 2]){
        swap(arr[index],arr[(index * 2)]);
        index = index * 2;
        heapify(arr,range,index);
      }
    }
  }
}
void heapSort(int arr[], int len){
  buildHeap(arr,len);
  for(int i = len-1;i > 0;i--){
    swap(arr[1],arr[i]);
    heapify(arr,i);
  }
  if(arr[1] > arr[2]){
    swap(arr[1],arr[2]);
  }
  
}
int main() 
{    
  // PQueue p;
  // int arr[7] = {4,3,8,2,5,7,6};
  // string meep[7] = {"bob","pat","george","gordon","mop","eobard","clark"};
  // for(int i = 0;i < 7;i++){
  //   p.Enqueue(arr[i],meep[i]);
  // }
  // p.Dequeue();
  // p.Dequeue();
  // MinHeapP h(arr,7,8);
  // h.DeleteMin();
  // h.printHeap();
  int arr[8] = {-1,4,3,12,9,5,7,6};
  heapSort(arr,8);
  printArray(arr,8);
};
  



