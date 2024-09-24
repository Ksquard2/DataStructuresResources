#include <iostream>


using namespace std;

void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout<<endl;
} 

void printArray(int arr[5])
{
  for(int x = 0; x < 5;x++)
  {
    cout<<arr[x]<<" ";
  }
  cout<<endl;
}
void ObubbleSort(int arr[6])
{
  cout<<"Orignal List: ";
  printArray(arr);
  int tracker = 0;
  for(int i = 0;i < 6;i++)
  {
    tracker = 0;
    for(int j = 0;j < 6-i-1;j++)
    {
        if(arr[j] > arr[j+1])
        {  
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            tracker++;
        } 
    }  
    printArray(arr);
    if(tracker == 0)
    {
        break;
    }
  }
}

// void NbubbleSort(int arr[5])
// {
 
//   for(int i = 0;i < 5;i++)
//   {

//     for(int j = 0;j < 5-i-1;j++)
//     {
//         if(arr[j] > arr[j+1])
//         {  
//             int temp = arr[j];
//             arr[j] = arr[j+1];
//             arr[j+1] = temp;
//         } 
//     }  
//     printArray(arr);
//   }
// }

void SelectionSort(int arr[5])
{
  int min = 1;
  for(int i = 0;i < 4;i++)
  {
      for(int j = i+1; j < 5;j++)
      {
          if(arr[j] < arr[min])
              min = j;
      }
      
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i]  = temp;
      printArray(arr);
  }

}

void insertion(int arr[5])
{
  for(int i = 0;i < 4;i++)
  {
      for(int j = i+1;j > 0;j--)
      {
        if(arr[j-1] > arr[j])
        {
          int temp = arr[j-1];
          arr[j-1] = arr[j];
          arr[j] = temp;
        }
        else break;
      }
      printArray(arr); 
  }
}
void merge(int arr1[4], int arr2[4], int res[8])
{  
    int index1 = 0;
    int index2 = 0;
    int indexr = 0;
    while(indexr <= 8)
    {
      if(res[7] != 0)
      {
        break;
      }
      if(arr1[index1] <= arr2[index2])
      {
        res[indexr] = arr1[index1];
        index1++;
        indexr++;
      }
      else
      {
        res[indexr] = arr2[index2];
        index2++;
        indexr++;
        // cout<<arr2[index2]<<endl;
      }
      printArray(res);
    }
    
}

void BubbleSort(int arr[5])
{
  cout<<"Orignal List: ";
  printArray(arr);
  for(int i = 0;i < 5;i++)
  {
    for(int j = 0;j < 5-i-1;j++)
    {
        if(arr[j] > arr[j+1])
        {  
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        } 
    }  
    printArray(arr);
  }
  
}

int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) 
            mx = arr[i]; 
    }
    return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 

    int output[n]; 
    int i, count[10] = {0}; 

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++; 

    }
    print(count,10);


    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
        

    }

    

    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--;
  
        
    } 
    //{ 543, 9, 27, 765, 329 }; 
    print(output,5);
    for (i = 0; i < n; i++){ 
        arr[i] = output[i]; 
    }
} 

void radixsort(int arr[], int n) 
{ 


    int m = getMax(arr, n); 

    for (int exp = 1; m / exp > 0; exp *= 10){ 
        countSort(arr, n, exp); 
    }
} 

int binarySearch(int arr[], int low, int high, int val){
  if(low == high)
  {
    return -1;
  }
  int mid = (low + high)/2;
  
  if(arr[mid] == val)
  {
    return mid;
  }
  else if(arr[mid] > val)
  {
    return binarySearch(arr, low, mid, val);
  }
  else
  {
    return binarySearch(arr, mid, high, val);
  }
  
}
int binarySearchI(int arr[], int low, int high, int val){
  while(low != high)
  {
    int mid = (low + high)/2;
    if(arr[mid] == val)
    {
      return mid;
    }
    else if(arr[mid] > val){
      high = mid;
    }
    else{
      low = mid;
    }
  }
  return -1;
}
int main() {
int arr[6] = {300,8,66,59,31,7127};
  ObubbleSort(arr);
  
  



}