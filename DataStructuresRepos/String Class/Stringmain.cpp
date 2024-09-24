#include <iostream>
#include "StringClass.h"
#include <string>
using namespace std;

bool isEqual(String s, string str)
{
  if(str.length() != s.len())
  {
    return false;
  }
  for(int i  = 0;i < str.length(); i++)
  {
    if(s.arr[i] != str[i])
    {
      return false;
    }
  }
  return true;
}

void unitTestDeleteAll1()
{
  String s("Hello");
  s.deleteAll('l');
  if(isEqual(s,"Heo")){
    cout<< "Test 1 Passed" << endl;
  }
  else cout<< "Test 1 Failed" << endl;
}
void unitTestDeleteAll2()
{
  String s("Hello");
  s.deleteAll('v');
  if(isEqual(s,"Hello")){
    cout<< "Test 2 Passed" << endl;
  }
  else cout<< "Test 2 Failed" << endl;
}
void unitTestInsertAt1()
{
  String s("Hllo");
  s.insertAt(1, 'e');
  if(isEqual(s,"Hello")){
    cout<< "Test 3 Passed" << endl;
  }
  else cout<< "Test 3 Failed" << endl;
}
void unitTestInsertAt2()
{
  String s("Hello");
  s.insertAt(9, 'e');
  if(isEqual(s,"Hello")){
    cout<< "Test 4 Passed" << endl;
  }
  else cout<< "Test 4 Failed" << endl;
}
void unitTestInsertAt3(){
  String s("123456789012345");
  s.insertAt(9, 'e');
  if(isEqual(s,"123456789012345"))
  {
    cout<< "Test 5 Passed" << endl;
  }
  else cout<< "Test 5 Failed" << endl;
}
void unitTestDeleteAt1()
{
  String s("Hello");
  s.deleteAt(4);
  if(isEqual(s,"Hell")){
    cout<< "Test 6 Passed" << endl;
  }
  else cout<< "Test 6 Failed" << endl;
}
void unitTestDeleteAt2()
{
  String s("Hello");
  s.deleteAt(9);
  if(isEqual(s,"Hello")){
    cout<< "Test 7 Passed" << endl;
  }
  else cout<< "Test 7 Failed" << endl;
}
void unitTestDeleteAt3()
{
  String s;
  s.deleteAt('l');
  if(s.isEmpty()){
    cout<< "Test 10 Passed" << endl;
  }
  else cout<< "Test 10 Failed" << endl;
}
void unitTestAppend1()
{
  String s("Hell");
  s.append('o');
  if(isEqual(s,"Hello")){
    cout<< "Test 8 Passed" << endl;
  }
  else cout<< "Test 8 Failed" << endl;
}
void unitTestAppend2()
{
  String s("123456789012345");
  s.append('e');
  if(isEqual(s,"123456789012345")){
    cout<< "Test 9 Passed" << endl;
  }
  else cout<< "Test 9 Failed" << endl;
}
void uniteTestFull()
{
  String s("123456789012345");
  if(s.isFull()){
    cout<< "Test 11 Passed" << endl;
  }
  else cout<< "Test 11 Failed" << endl;
}
void unitTestEmpty()
{
  String s;
  if(s.isEmpty()){
    cout<< "Test 12 Passed" << endl;
  }
  else cout<< "Test 12 Failed" << endl;
}
void unitTestDeleteAll3()
{
  String s;
  s.deleteAll('l');
  if(s.isEmpty()){
    cout<< "Test 13 Passed" << endl;
  }
  else cout<< "Test 13 Failed" << endl;
}
void testAll()
{
  unitTestDeleteAll1();
  unitTestDeleteAll2();
  unitTestInsertAt1();
  unitTestInsertAt2();
  unitTestInsertAt3();
  unitTestDeleteAt1();

}







int main() {
    testAll();

}