#include <iostream>
#include "/Users/k2/Desktop/DataStructuresResources/DataStructuresRepos/Trees/TreeI.h"
#include "/Users/k2/Desktop/DataStructuresResources/DataStructuresRepos/Heaps/MaxHeap.h"
#include <chrono>
#include <vector>
using namespace std;
struct node{
  int data;
  node* next;
}
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout<<endl;
} 

void printArray(int arr[10])
{
  for(int x = 0; x < 10;x++)
  {
    if(arr[x] != -1){
      cout<<arr[x]<<" ";
    }
    
  }
  cout<<endl;
}
//prototypes
void heapSort(int arr[], int len);
vector<int> treeSort(vector<int>& arr);
void ObubbleSort(int arr[],int len);
void NOBubbleSort(int arr[],int len);
vector<int> mergeSortR(vector<int> arr);
void mergeSortI(int arr[], int l, int r);
void SelectionSort(int arr[],int len);
void radixsort(int arr[], int n); 
int binarySearchI(int arr[], int low, int high, int val);
int binarySearch(int arr[], int low, int high, int val);
int findRotatedMin(int arr[6],int l, int r);
void recurrenceRelation(int n,string str = "");
unsigned long long int recursion(unsigned long long int a, unsigned long long int prev = 1,unsigned long long int curr = 1);
unsigned long long int recursion2(unsigned long long int fib);
int main() 
{

  //   int f;
  // cout<<"Enter number to find the value of its fibonacci index: ";
  // cin>>f;
  // cout<<endl;

  // int fib = f;
  
  // auto starti = chrono::high_resolution_clock::now();
  
  // cout<<"The recursive 1 algorithm outputs: "<<recursion(fib)<<endl;

  // auto endi = chrono::high_resolution_clock::now();
  
  // cout<<endl;
  
  // double speedi = chrono::duration_cast<chrono::nanoseconds>(endi-starti).count();
  
  // cout<<(speedi / 1e+9)<<" seconds of performace time for Fibonacci iteration"<<endl;

  // cout<<endl;

  // auto startr = chrono::high_resolution_clock::now();
  
  // cout<<"The recursive algorithm outputs: "<<recursion2(fib+1)<<endl;
  
  // auto endr = chrono::high_resolution_clock::now();
  
  // cout<<endl;
  
  // double speedr = chrono::duration_cast<chrono::nanoseconds>(endr-startr).count();
  
  // cout<<(speedr / 1e+9)<<" seconds of performace time for Fibonacci recursion"<<endl;
  recurrenceRelation(8);
  // int arr[6] = {3,890,20,46,31,8};
  // mergeSort(arr, 0, 6);
  // for(int i = 0;i < 6;i++){
  //   cout<<arr[i]<<" ";
  // }
  // radixsort(arr,6);
// recurrenceRelation(5);
// int arr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
// insertion(arr,5);
// insertion(arr,3);
// insertion(arr,9);
// insertion(arr,1);
// insertion(arr,8);
// insertion(arr,4);
// insertion(arr,7);
}
void buildHeap(int arr[], int len){

  MaxHeap h(8);
  for (int i = 1;i < len; i++)
  {
    h.insert(arr[i]);
  }
  for(int i = 1;i < len;i++)
  {
    arr[i] = h.arr[i];
  }
}
void heapify(int arr[],int range,int index = 1){
  if((index * 2) + 1 < range)
  {
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
TreeI* vecToTree(vector<int>& arr){
  TreeI* tree = nullptr;
  for(int i = 0; i < arr.size(); i++)
  {
    tree = InsertAVL(tree, arr[i]);
  }
  return tree;
}

void inOrderV(vector<int>& meep, TreeI* root){
  if(root == NULL){
      return;
  }
  else{
    inOrderV(meep,root -> left);
    meep.push_back(root -> data); 
    inOrderV(meep, root -> right);
       
  }
}
vector<int> treeSort(vector<int>& arr){
  TreeI* root = vecToTree(arr);
  vector<int> answer;
  inOrderV(answer, root);
  return answer;
}
void ObubbleSort(int arr[],int len)
{
  cout<<"Orignal List: ";
  printArray(arr);
  int tracker = 0;
  for(int i = 0;i < len;i++)
  {
    tracker = 0;
    for(int j = 0;j < len-i-1;j++)
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

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> sortedArray;
    int i = 0, j = 0;

    // Merge the two halves
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            sortedArray.push_back(left[i]);
            i++;
        } else {
            sortedArray.push_back(right[j]);
            j++;
        }
    }

    // Append remaining elements
    while (i < left.size()) {
        sortedArray.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        sortedArray.push_back(right[j]);
        j++;
    }

    return sortedArray;
}

// Merge Sort function
vector<int> mergeSortR(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSortR(left), mergeSortR(right));
}

void merge(int arr[], int l, int m, int r) {
  int repSize = r - l;
  int rep[repSize];
  int l1 = l;
  int l2 = m;
  int index = 0;
  while(l1 < m && l2 < r) 
  {
    if(arr[l1] < arr[l2]) 
    {
      rep[index] = arr[l1++];
    } 
    else 
    {
      rep[index] = arr[l2++];
    }
    index++;
  }
  while(l1 < m) {
    rep[index++] = arr[l1++];
  }
  while(l2 < r) {
    rep[index++] = arr[l2++];
  }
  for(int i = 0; i < repSize; i++) 
  {
    arr[l + i] = rep[i];
  }
}

void mergeSortI(int arr[], int l, int r) {
  if(r - l <= 1) {
    return;
  }

  int m = l + (r - l) / 2;
  mergeSortI(arr, l, m);
  mergeSortI(arr, m, r);

  merge(arr, l, m, r);
}

void SelectionSort(int arr[],int len)
{
  int min = 1;
  for(int i = 0;i < len-1;i++)
  {
      for(int j = i+1; j < len;j++)
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


void NOBubbleSort(int arr[],int len)
{
  cout<<"Orignal List: ";
  printArray(arr);
  for(int i = 0;i < len;i++)
  {
    for(int j = 0;j < len-i-1;j++)
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
    // print(count,10);
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

int binarySearch(int arr[], int low, int high, int val){ //big O notation
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

int findRotatedMin(int arr[6],int l, int r)
{
  int m = (l+r)/2;
  if(l == r)
  {
    return arr[l];
  }
  else if(arr[m] > arr[r])
  {
    return findRotatedMin(arr, m+1,r);
  }
  else
  {
    return findRotatedMin(arr,l,m);
  }
}

void recurrenceRelation(int n,string str = ""){
  if(n != 1){
    cout<<"C("<<n<<") = ";
    string added = " + 4("+to_string(n-1)+")";
    str = str+added;
    cout<<"C("<<to_string(n-1)<<") "<<str<<endl;
    recurrenceRelation(n-1,str);
  }
}
node* insertionSort(node* head, int val){
  node* nn = new node;
  nn->data = val;
  nn->next = NULL;
  if(!head){
      head = nn;
  }
  else if(val < head->data){
      nn->next = head;
      head = nn;
  }
  else{
      node* temp = head;
      while(temp->next != NULL && temp->next->data < val){
          temp = temp->next;
      }
      if(temp->next != NULL){
          nn->next = temp->next;
          temp->next = nn;
      }
      else{
          temp->next = nn;
      }
  }
  return head;
}
unsigned long long int recursion(unsigned long long int a, unsigned long long int prev = 1,unsigned long long int curr = 1)
{
  if (a == 1)
  {

    return curr;
  }
  else return recursion(a-1,curr,curr+prev);
}

unsigned long long int recursion2(unsigned long long int fib) 
{
   if (fib <= 1) 
   {
      return fib;
   }
   else 
   {
      return (recursion2(fib-1) + recursion2(fib-2));
   }
}