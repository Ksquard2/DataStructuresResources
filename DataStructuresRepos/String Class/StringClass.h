#include <iostream>
#include <string>
using namespace std;
class String
{
public:
  char arr[15];
  int length;
  String()
  {
    for(int i = 0;i < 30;i++)
    {
      arr[i] = ' ';
    }
    length = 0;
  }
  String(string str)
  {
    
    for(int i = 0;i <str.length(); i++ )
    {
      arr[i] = str[i];
    }
    length = str.length();
  }
  bool isEmpty(){
    return length == 0;
  }
  bool isFull(){
    return length == 15;
  }
  int len()
  {
    return length;
  }
  void append(char c)
  {
    if(isFull())
    {
      cout << "String is full" << endl;
    }
    else
    {
      arr[length] = c;
      length++;
    }
  }
  char deleteAt(int i)
  {
    char c = arr[i];
    if(i >= length){
      return '/';
    }
    if(!isEmpty()){
      for(int j = i; j < length; j++){
        arr[j] = arr[j+1];
      }
      length--;
      return c;
    }
    else return '/';
  }
  void print(){
    for(int i = 0; i < length; i++)
    {
      cout << arr[i];
    }
    cout<<endl;
  }
  int Pos(char c)
  {
    for(int i = 0; i < length; i++){
      if(arr[i] == c){
        return i;
      }
    }
    return -1;
  }
  char getChar(int i)
  {
    if(arr[i] == ' ')
    {
      return '/';
    }
    else return arr[i];
  }
  void insertAt(int i,char c)
  {
    if(!isFull())
    {
      if(i > length-1)
      {
        cout<<"String too small"<<endl;
      }
      else
      {
        for(int t = length-1;t >= i;t--)
        {
        arr[t+1]= arr[t];
        }
        arr[i] = c;
        length++;
      }
    }
    else cout<<"String is full"<<endl;
  }
  
  void deleteAll(char c)
  {
    if(isEmpty()) cout<<"String is empty"<<endl;
    else 
    {
      for(int i = 0; i < length; i++)
        {
          while(arr[i] == c)
          {
            for(int j = i; j < length; j++)
            {
              arr[j] = arr[j+1];
            }
            length--;
          }
        }
    }
  }
};