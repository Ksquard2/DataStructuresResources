#pragma once


#include <iostream>
#include <math.h>
using namespace std;

class MaxHeapP
{
  private:
    friend class PQueue;
    int *arr;
    int size;
    int capacity;
    int start;

  public:
    MaxHeapP(int cap)
    {
      start = 1;
      size = 1;
      capacity = cap;
      arr = new int[cap];
      for(int i = 0;i < cap;i++){
        arr[i] = 0;
      }
    }
    bool IsEmpty()
    {
      return size == 1;
    }
    bool IsFull()
    {  
      return ( size == capacity ) ;
    }
    
    int* getArray()
    {
      return arr;
    }
    void PercolateUp(int last_index)
    {
      if(arr[last_index] > arr[last_index/2] && last_index != 1)
      {      
          swap(arr[last_index],arr[last_index/2]);
          last_index/=2;
          PercolateUp(last_index);
      }
    }
void setSize(){
  int i = capacity-1;
  while(arr[i] == 0)
  {
    i--;
  }
  size = i;
}
    void insert(int x)
    {
        if(arr[1] == 0){
          arr[1] = x;

        }
        else{
          this->getArray()[size] = x;
          PercolateUp(size);
        }
        size++;
      
      
    }
void PercolateDown(int index,int range)
// use “compare-and-replace” approach
{
  if((index * 2) + 1 < range)
  {
    if(arr[index * 2] < arr[(index * 2) + 1]){
      if(arr[index] < arr[(index * 2) + 1]){
        swap(arr[index],arr[(index * 2) + 1]);
        index = index * 2;
        index++;
        PercolateDown(index,range);
      }
    }
    else{
      if(arr[index] < arr[index * 2]){
        swap(arr[index],arr[(index * 2)]);
        index = index * 2;
        PercolateDown(index,range);
      }
    }
  }
  }
  void DeleteMax()
    {
      if (!IsEmpty())
       {  
        swap(arr[1],arr[size-1]);
        size--;
        PercolateDown(1,size);
       }
    }
    int linear_search(int key)
    {
      for (int i = 0; i < size; i++){
        if (arr[i] == key)
        {
          cout<<key<<" is found at index "<<i<<endl;
          return key;
        }
      }
      cout<<"Value not Found"<<endl;
      return -1;
    }
    
    int height()
    {
      return ceil(log2(size + 1));
    }
    
  void printHeapLin(){
    for(int i = 1; i < size; i++){
      cout<<arr[i]<<" ";
    }
  }
  void printHeap(){
    int checker = 1;
    int indent = 0;
    int spaces = (capacity-1)/2;
    for(int i = 1;i<capacity;i++)
    {
      if(i == size+1)
      {
        break;
      }
      string space = "";
      if(indent == checker)
      {
        cout<<endl;
        indent = 0;
        checker = checker*2;
        spaces = spaces/2;
      }
        for(int j = 0;j < spaces;j++)
        {
          space = space+" ";
        }
        if(indent == 0)
        {
          cout<<space<<arr[i];
        }
        else
        {
          for(int j = 0;j < spaces+1;j++)
          {
            space = space+" ";
          }
          cout<<space<<arr[i];
        }
      indent++;
      }
    cout<<endl;
  }

};