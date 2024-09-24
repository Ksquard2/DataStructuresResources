#include <iostream>
using namespace std;
#include <math.h>
class TreeA
{
public:
  int arr[16];
  int size;


  TreeA(){
    for(int i = 0;i<16;i++){
      arr[i] = 0;
    }
    size = 0;

  }
  TreeA(int data){
    for(int i = 0;i<16;i++){
      arr[i] = 0;
    }
    arr[1] = data;
    size = 1;

  }
void insertA(int data, int ic = 1){
  if(arr[ic] == 0){
    
    arr[ic] = data;
    
  }
  else if(arr[ic] > data)
  {
    if(arr[ic*2] == 0)
    {
      arr[ic*2] = data;
      if(size < ic*2)
      {
        size = ic*2;
      }
      ic = 1;
    }
    else{

      insertA(data, ic*2);
    }
  }
  else
  {
    if(arr[(ic*2)+1] == 0)
    {
      arr[(ic*2)+1] = data;
      if(size < (ic*2)+1)
      {
        size = (ic*2)+1;
      }
      ic = 1;
    }
    else{
      insertA(data, (ic*2)+1);
    }
  }
}
bool isIn(int data, int ic = 1){
  if(arr[ic] == 0){
    return false;
  }
  else if(arr[ic] == data){
    return true;
  }
  else if(arr[ic] > data){
    return isIn(data, ic*2);
  }
  else if(arr[ic] < data){
    return isIn(data, (ic*2)+1);
  }
  return false;
}

bool isBST(int i = 1){
  if(arr[i] == 0){
    return true;
  }

  else if(arr[i*2] == 0 && arr[(i*2)+1] == 0){
    return true;
  }
  else if(arr[i*2] != 0 && arr[i*2] <= arr[i] && arr[(i*2)+1] == 0)
  {
    return isBST(i*2);
  }
  else if(arr[(i*2)+1] != 0 && arr[(i*2)+1] > arr[i] && 
    arr[i*2] == 0)
  {
    return isBST((i*2)+1);
  }
  else if(arr[(i*2)+1] != 0 && arr[(i*2)+1] > arr[i] && arr[i*2] != 0 && arr[i*2] <= arr[i]){
  
    return isBST((i*2)+1) && isBST(i*2);
  }
  else {
    return false;
  }
}
void preOrder(int i = 1)
{
  if(arr[i] == 0){
    cout<<". ";
  }
  else if(i > size)
  {
    cout<<"";
  }
  else{
    cout<<arr[i]<<" ";
    preOrder(i*2);
    preOrder((i*2)+1);
  }
}
void postOrder(int i = 1)
{
  
  if(arr[i] == 0){
    cout<<". ";
  }
  else if(i > size)
  {
    cout<<"";
  }
  else
  {
    
    postOrder(i*2);
    postOrder((i*2)+1);
    cout<<arr[i]<<" ";
  }
}
void inOrder(int i = 1)
{
  if(arr[i] == 0){
    cout<<". ";
  }
  else if(i > size)
  {
    cout<<"";
  }
  else{

    inOrder(i*2);
    cout<<arr[i]<<" ";
    inOrder((i*2)+1);
  }
}
int height()
{
  int i = 15;
  while(arr[i] == 0)
  {
    i--;
  }
  double x = log2(double(i)+1.0);
  double y = x - int(x);
  if(y != 0){
    return log2(i+1)+1;
  }
  else return log2(i+1);
}

void printTreeA(){
  int checker = 1;
  int indent = 0;
  int spaces = 15/2;

  for(int i = 1;i<16;i++)
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
        if(arr[i] != 0){
          cout<<space<<arr[i];
        }
        else{
          cout<<space<<" ";
        }
        
      }
      else
      {
        for(int j = 0;j < spaces+1;j++)
        {
          space = space+" ";
        }
        if(arr[i] != 0){
          cout<<space<<arr[i];
        }
        else
        {
          cout<<space<<" ";
        }
      }
    indent++;
    }
}

};