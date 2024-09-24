#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;
int capacity  = 8;
int main() 
{   
  MinHeap h(8);
  for (int i = 6;i >= 1; i--)
  {
    h.insert(i);
  }
  h.printHeap();
  h.DeleteMin(6);
  h.printHeap();
}
  
