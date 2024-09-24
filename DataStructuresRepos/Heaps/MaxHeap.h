#include <iostream>
#include <math.h>
using namespace std;

class MaxHeap
{
  public:
    int *arr;
    int size;
    int capacity;
    int start;
    
    bool IsEmpty(){
      return size == 1;
    }
    bool IsFull()
    {  
      return ( size == capacity ) ;
    }
    MaxHeap(int cap)
    {
      start = 1;
      size = 1;
      capacity = cap;
      arr = new int[cap];
    }
    int* getArray(){
      return arr;
    }
    void PercolateUp(int last)
    {
      bool done = false;
      int i = last+1;
      while(!done)
      {
        if(arr[i/2] > arr[i])
        {
          done = true;
        }
        else
        {
          int swap_element = arr[i/2];
          arr[i/2] = arr[i];
          arr[i] = swap_element;
          i = i/2;
        }

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
      setSize();
      if(arr[1] == 0){
        arr[1] = x;

      }
      else{
        this->getArray()[size+1] = x;
        PercolateUp(size);
      }
      setSize();
    }
void PercolateDown(int start_index)
// use “compare-and-replace” approach
{
  int i = start_index;
  bool done = false;
  while(!done && i*2 < capacity){
    if(arr[i*2] == 0){
      done = true;
    }
    else if(arr[(i*2)+1] == 0){
        done = true;
      }
    else if(arr[i] < arr[i*2] && arr[i] < arr[(i*2)+1])
    {

      if(arr[(i*2)+1] < arr[i*2]){
        int temp = arr[i];
        arr[i] = arr[i*2];
        arr[i*2] = temp;
        i = i*2;
      }
      else
      {
        int temp = arr[i];
        arr[i] = arr[(i*2)+1];
        arr[(i*2)+1] = temp;
        i = (i*2)+1;
      }

    }
    else{
      done = true;
    }
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
    void DeleteMax(int maximal_value)
    {
      if (!IsEmpty())
       {  
        maximal_value = arr[1] ;
        arr[ 1 ] = arr[ size ];
        arr[ size ] = 0;
        PercolateDown(1);
       } 
      setSize();
    }
  void printHeap(){
    int checker = 1;
    int indent = 0;
    int spaces = (capacity-1)/2;
    for(int i = start;i<capacity;i++)
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