#include <iostream>
#include "LinkListInt.cpp"
#include "LinkListChar.cpp"
#include "LinkListString.cpp"
#include <string>
using namespace std;


NodeI *arrToList(int *arr, int len)
{
 
    NodeI *head = new NodeI(arr[0]);
  cout<<arr[0]<<endl;
    for(int i = 1; i < len;i++)
    {
      
        int val = arr[i];
        head->append(val);
    }
    return head->next;
}


int listSum(NodeI *head)
{
  if(head == NULL)
  {
    return 0;
  }
  else
  {
    return head->data + listSum(head->next);
  }
}

int listProduct(NodeI *head)
{
  if(head == NULL)
  {
    return 1;
  }
  else
  {
    return head->data * listProduct(head->next);
  }
}
int indexOf(NodeI *head,int val)
{
  auto temp = head;
  int index = 0;
  while(temp->data != val && temp != nullptr)
  {
    index++;
    temp = temp->next;
  }
  if(temp != nullptr)
  {
    return index;
  }
  else return -1;
  // while(temp->next != nullptr)
  // {
  //   temp = temp->next;
  //   if(temp->data == val)
  //   {
  //     return index;
  //   }

  //   else index++;
  //   cout<<index<<endl;
  // }
  // return -1;

}
// NodeI *insertAt(NodeI *head,int val,int index)
// {
//   NodeI* temp = head;
//   int i = 0;
//   NodeI* value;
//   value = new NodeI(val);
//   while(i < index-1 && temp != nullptr)
//   {
//     temp = temp->next;
//     i++;
//   }
//   if(temp != nullptr)
//   {
//     value->next = temp->next;
//     temp->next = value;
//   }
//   return head;
// }

NodeI *rotate(NodeI* head, int n)
{
  if(head->isEmpty()){
    return head;
  }
  if(head->next == nullptr){
    return head;
  }
  NodeI* Last = head;
  int i = (head->len() - (n%(head->len())));
  while (Last->next != nullptr) 
  {
    Last = Last->next;

  }
  
  Last->next = head;
  while (i > 0)
  {
    head = head->next;
    Last = Last->next;
    i--;
  }
  Last->next = nullptr;
  return head;
}

bool isEqual(NodeI *head1, NodeI *head2){
  if(head1->isEmpty() && head2->isEmpty()){
    return true;
  }
  if(head1->isEmpty() || head2->isEmpty()){
    return false;
  }
  if(head1->len() != head2->len()){
    return false;
  }
  
  NodeI* temp1 = head1;
  NodeI* temp2 = head2;
  while(temp1 != nullptr && temp2 != nullptr){
    if(temp1->data != temp2->data){
      return false;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return true;
}
void insertString(NodeI* s1, NodeI* s2, int k) 
{
  NodeI* temp1 = s1;
  NodeI* temp2 = s2;
  if (temp1 == nullptr || temp2 == nullptr) 
  {
    return;
  }
  for (int i = 0; i < k - 1; i++) 
  {
    temp1 = temp1->next;
  }
  while  (temp2->next != nullptr) 
  {
    temp2 = temp2->next;
  }

  temp2->next = temp1->next;
  temp1->next = s2;
  s1->prettyPrint();
}

void deleteAll(NodeI* head, int val)
{
  NodeI* temp = head;
  NodeI* prev = NULL;
  while(temp->data == val){
    head = temp->next;
    temp = temp->next;
  }
  while(temp != NULL){
    if(temp->data == val){
      prev->next = temp->next;
      temp = temp->next;
      prev->next = NULL;
    }
    else
    {
      prev = temp;
      temp = temp->next;
    }
  }
}

void appendRHelper(NodeI* head, int val)
{
  if(head == NULL)
  {
    head = new NodeI(val);
  }
  if(head->next == nullptr)
  {
    head->next = new NodeI(val);
  }
  else{
    appendRHelper(head->next, val);
  }
}
void appendR(NodeI* head, int val)
{
  NodeI *temp = head;
  appendRHelper(temp, val);
  
}

void unitTestEmpty1()
{
  NodeI* LL = new NodeI();
  if(LL->isEmpty()) cout<<"Test 1 Passed"<<endl;
  else cout<<"Test 1 Failed"<<endl;
}
void unitTestEmpty2()
{
  NodeI* LL = new NodeI(1);
  if(LL->isEmpty()) cout<<"Test 2 Failed"<<endl;
  else cout<<"Test 2 Passed"<<endl;
}
void unitTestappend1()
{
  int arr[6]= {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->append(7);
  int arr2[7] = {1,2,3,4,5,6,7};
  NodeI* answer = new NodeI(arr2,7);;
  if(isEqual(LL,answer)) cout<<"Test 3 Passed"<<endl;
  else cout<<"Test 3 Failed"<<endl;
}
void unitTestappend2()
{
  NodeI* LL = new NodeI();
  LL->append(7);
  NodeI* answer = new NodeI(7);
  if(isEqual(LL,answer)) cout<<"Test 4 Passed"<<endl;
  else cout<<"Test 4 Failed"<<endl;
}
void unitTestInsertAt1(){
  int arr[6]={1,2,3,4,6,7};
  NodeI* LL = new NodeI(arr,6);
  LL->insertAt(5,4);
  int arr2[7] = {1,2,3,4,5,6,7};
  NodeI* answer = new NodeI(arr2,7);
  if(isEqual(LL,answer)) cout<<"Test 5 Passed"<<endl;
  else cout<<"Test 5 Failed"<<endl;
}
void unitTestInsertAt2()
{
  NodeI* LL = new NodeI();
  LL->insertAt(7,0);
  NodeI* answer = new NodeI(7);
  if(isEqual(LL,answer)) cout<<"Test 6 Passed"<<endl;
  else cout<<"Test 6 Failed"<<endl;
}
void unitTestInsertAt3()
{
  NodeI* LL = new NodeI();
  LL->insertAt(7,8);
  NodeI* answer = new NodeI(7);
  if(!LL->isEmpty()) cout<<"Test 7 Failed"<<endl;
  else cout<<"Test 7 Passed"<<endl;
}
void unitTestInsertAt4(){
  int arr[6] = {1,2,3,4,6,7};
  NodeI* LL = new NodeI(arr,6);
  LL->insertAt(5,9);
  int arr2[6]={1,2,3,4,6,7};
  NodeI* answer = new NodeI(arr2,6);
  if(isEqual(LL,answer)) cout<<"Test 8 Passed"<<endl;
  else cout<<"Test 8 Failed"<<endl;
}
void unitTestPos1(){
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  if(LL->posOf(3) == 2) cout<<"Test 9 Passed"<<endl;
  else cout<<"Test 9 Failed"<<endl;
}
void unitTestPos2(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  if(LL->posOf(30) == -1) cout<<"Test 10 Passed"<<endl;
  else cout<<"Test 10 Failed"<<endl;
}
void unitTestPos3(){
  NodeI* LL = new NodeI();
  if(LL->posOf(0) == -1) cout<<"Test 11 Passed"<<endl;
  else cout<<"Test 11 Failed"<<endl;
}
void unitTestelementAt1(){
  int arr[6]={1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  if(LL->elementAt(3) == 4) cout<<"Test 12 Passed"<<endl;
  else cout<<"Test 12 Failed"<<endl;
}
void unitTestelementAt2(){
NodeI* LL = new NodeI();
  if(LL->elementAt(3) == -1) cout<<"Test 13 Passed"<<endl;
  else cout<<"Test 13 Failed"<<endl;
}
void unitTestelementAt3(){
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  if(LL->elementAt(12) == -1) cout<<"Test 14 Passed"<<endl;
  else cout<<"Test 14 Failed"<<endl;
}
void unitTestIsIn1(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  if(LL->IsIn(3)) cout<<"Test 15 Passed"<<endl;
  else cout<<"Test 15 Failed"<<endl;
}
void unitTestIsIn2(){
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  if(!LL->IsIn(12)) cout<<"Test 16 Passed"<<endl;
  else cout<<"Test 16 Failed"<<endl;
}
void unitTestDeleteVal1(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteVal(3);
  int arr2[5] = {1,2,4,5,6};
  NodeI* answer = new NodeI(arr2,5);
  if(isEqual(LL,answer)) cout<<"Test 17 Passed"<<endl;
  else cout<<"Test 17 Failed"<<endl;
}
void unitTestDeleteVal2(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteVal(9);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI* answer = new NodeI(arr2,6);
  if(isEqual(LL,answer)) cout<<"Test 23 Passed"<<endl;
  else cout<<"Test 23 Failed"<<endl;
}
void unitTestDeleteVal3(){
  NodeI* LL = new NodeI();
  LL->DeleteVal(9);
  if(LL->isEmpty()) cout<<"Test 24 Passed"<<endl;
  else cout<<"Test 24 Failed"<<endl;
}
void unitTestDeleteAt1()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteAt(3);
  int arr2[5]={1,2,3,5,6};
  NodeI* answer = new NodeI(arr2,5);
  if(isEqual(LL,answer)) cout<<"Test 18 Passed"<<endl;
  else cout<<"Test 18 Failed"<<endl;
}
void unitTestDeleteAt2()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteAt(-1);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI* answer = new NodeI(arr2,6);
  if(isEqual(LL,answer)) cout<<"Test 19 Passed"<<endl;
  else cout<<"Test 19 Failed"<<endl;
}
void unitTestDeleteAt3()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteAt(10);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI* answer = new NodeI(arr2,6);
  if(isEqual(LL,answer)) cout<<"Test 20 Passed"<<endl;
  else cout<<"Test 20 Failed"<<endl;
}
void unitTestDeleteAt4()
{
  NodeI* LL = new NodeI();
  LL->DeleteAt(3);
  if(LL->isEmpty()) cout<<"Test 21 Passed"<<endl;
  else cout<<"Test 21 Failed"<<endl;
}
void unitTestIsIn3(){
  NodeI* LL = new NodeI();
  if(!LL->IsIn(3)) cout<<"Test 22 Passed"<<endl;
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
  cout<<"hello"<<endl;
unitTestDeleteVal();
//  int arr[5] = {2,3,4,5,6};
//   NodeI* x = new NodeI();
//   for(int i = 0;i < 5;i++){
//     x->append(arr[i]);
//   }
//   cout<<"hello"<<endl;
//   x->prettyPrint();
  
  // x->append(9);
}
