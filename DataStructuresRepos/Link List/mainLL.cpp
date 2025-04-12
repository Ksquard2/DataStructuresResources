#include <iostream>
#include "LinkListInt.cpp"
#include "LinkListChar.cpp"
#include "LinkListString.cpp"
#include "Polynomial.h"
#include <string>
#include <map>
using namespace std;

void unitTestEmpty1()
{
  NodeI LL;
  if(LL.isEmpty()) cout<<"Test 1 Passed"<<endl;
  else cout<<"Test 1 Failed"<<endl;
}
void unitTestEmpty2()
{
  NodeI LL(1);
  if(LL.isEmpty()) cout<<"Test 2 Failed"<<endl;
  else cout<<"Test 2 Passed"<<endl;
}
void unitTestappend1()
{
  int arr[6]= {1,2,3,4,5,6};
  NodeI LL(arr,6);
  LL.append(7);
  int arr2[7] = {1,2,3,4,5,6,7};
  NodeI answer(arr2,7);;
  if(LL==answer) cout<<"Test 3 Passed"<<endl;
  else cout<<"Test 3 Failed"<<endl;
}
void unitTestappend2()
{
  NodeI LL;
  LL.append(7);
  NodeI answer(7);
  if(LL==answer) cout<<"Test 4 Passed"<<endl;
  else cout<<"Test 4 Failed"<<endl;
}
void unitTestInsertAt1(){
  int arr[6]={1,2,3,4,6,7};
  NodeI LL(arr,6);
  LL.insertAt(5,4);
  LL.prettyPrint();
  int arr2[7] = {1,2,3,4,5,6,7};
  NodeI answer(arr2,7);
  answer.prettyPrint();
  if(LL==answer) cout<<"Test 5 Passed"<<endl;
  else cout<<"Test 5 Failed"<<endl;
}
void unitTestInsertAt2()
{
  NodeI LL;
  LL.insertAt(7,0);
  NodeI answer(7);
  if(LL==answer) cout<<"Test 6 Passed"<<endl;
  else cout<<"Test 6 Failed"<<endl;
}
void unitTestInsertAt3()
{
  NodeI LL;
  LL.insertAt(7,8);
  if(!LL.isEmpty()) cout<<"Test 7 Failed"<<endl;
  else cout<<"Test 7 Passed"<<endl;
}
void unitTestInsertAt4(){
  int arr[6] = {1,2,3,4,6,7};
  NodeI LL(arr,6);
  LL.insertAt(5,9);
  int arr2[6]={1,2,3,4,6,7};
  NodeI answer(arr2,6);
  if(LL==answer) cout<<"Test 8 Passed"<<endl;
  else cout<<"Test 8 Failed"<<endl;
}
void unitTestPos1(){
 int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  if(LL.posOf(3) == 3) cout<<"Test 9 Passed"<<endl;
  else cout<<"Test 9 Failed"<<endl;
}
void unitTestPos2(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  if(LL.posOf(30) == -1) cout<<"Test 10 Passed"<<endl;
  else cout<<"Test 10 Failed"<<endl;
}
void unitTestPos3(){
  NodeI LL;
  if(LL.posOf(0) == -1) cout<<"Test 11 Passed"<<endl;
  else cout<<"Test 11 Failed"<<endl;
}
void unitTestelementAt1(){
  int arr[6]={1,2,3,4,5,6};
  NodeI LL(arr,6);
  if(LL.elementAt(3) == 4) cout<<"Test 12 Passed"<<endl;
  else cout<<"Test 12 Failed"<<endl;
}
void unitTestelementAt2(){
NodeI LL;
  if(LL.elementAt(3) == -1) cout<<"Test 13 Passed"<<endl;
  else cout<<"Test 13 Failed"<<endl;
}
void unitTestelementAt3(){

 int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  if(LL.elementAt(12) == -1) cout<<"Test 14 Passed"<<endl;
  else cout<<"Test 14 Failed"<<endl;
}
void unitTestIsIn1(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  if(LL.IsIn(3)) cout<<"Test 15 Passed"<<endl;
  else cout<<"Test 15 Failed"<<endl;
}
void unitTestIsIn2(){
 int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  if(!LL.IsIn(12)) cout<<"Test 16 Passed"<<endl;
  else cout<<"Test 16 Failed"<<endl;
}
void unitTestDeleteVal1(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  LL.DeleteVal(3);
  int arr2[5] = {1,2,4,5,6};
  NodeI answer(arr2,5);
  if(LL==answer) cout<<"Test 17 Passed"<<endl;
  else cout<<"Test 17 Failed"<<endl;
}
void unitTestDeleteVal2(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  LL.DeleteVal(9);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI answer(arr2,6);
  if(LL==answer) cout<<"Test 23 Passed"<<endl;
  else cout<<"Test 23 Failed"<<endl;
}
void unitTestDeleteVal3(){
  NodeI LL;
  LL.DeleteVal(9);
  if(LL.isEmpty()) cout<<"Test 24 Passed"<<endl;
  else cout<<"Test 24 Failed"<<endl;
}
void unitTestDeleteAt1()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  LL.DeleteAt(3);
  int arr2[5]={1,2,3,5,6};
  NodeI answer(arr2,5);
  if(LL==answer) cout<<"Test 18 Passed"<<endl;
  else cout<<"Test 18 Failed"<<endl;
}
void unitTestDeleteAt2()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  LL.DeleteAt(-1);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI answer(arr2,6);
  if(LL==answer) cout<<"Test 19 Passed"<<endl;
  else cout<<"Test 19 Failed"<<endl;
}
void unitTestDeleteAt3()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI LL(arr,6);
  LL.DeleteAt(10);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI answer(arr2,6);
  if(LL==answer) cout<<"Test 20 Passed"<<endl;
  else cout<<"Test 20 Failed"<<endl;
}
void unitTestDeleteAt4()
{
  NodeI LL;
  LL.DeleteAt(3);
  if(LL.isEmpty()) cout<<"Test 21 Passed"<<endl;
  else cout<<"Test 21 Failed"<<endl;
}
void unitTestIsIn3(){
  NodeI LL;
  if(!LL.IsIn(3)) cout<<"Test 22 Passed"<<endl;
  else cout<<"Test 22 Failed"<<endl;
}
void unitTestDeleteAt(){
  unitTestDeleteAt1();
  unitTestDeleteAt2();
  unitTestDeleteAt3();
  unitTestDeleteAt4();
}
void unitTestInsertAt(){
  unitTestInsertAt1();
  unitTestInsertAt2();
  unitTestInsertAt3();
  unitTestInsertAt4();
}

void unitTestelementAt()
{
  unitTestelementAt1();
  unitTestelementAt2();
  unitTestelementAt3();
}
void unitTestisEmpty(){
  unitTestEmpty1();
  unitTestEmpty2();
}

void unitTestappend(){
  unitTestappend1();
  unitTestappend2();
}
void unitTestIsIn(){
  unitTestIsIn1();
  unitTestIsIn2();
  unitTestIsIn3();
}
void unitTestPos(){
  unitTestPos1();
  unitTestPos2();
  unitTestPos3();
}
void unitTestDeleteVal(){
  unitTestDeleteVal1();
  unitTestDeleteVal2();
  unitTestDeleteVal3();
}






int main() 
{
  unitTestInsertAt();
  
  
//   int Length;
//  cout<<"How Many Polynomials: ";
//   cin>>Length;
//   string arr[Length];
//   for(int i = 0; i < Length; i++){
//     cout<<"Enter Polynomial "<<i+1<<": ";
//     cin>>arr[i];
//   }
//   NodePoly* final = AddPolynomials(arr,Length);
//   cout<<"Adding ";
//   final->prettyPrint();
//   NodePoly *PolyF = MultiplyPolynomials(arr,Length);
//   cout<<"Multiplying ";
//   PolyF->prettyPrint();

}
