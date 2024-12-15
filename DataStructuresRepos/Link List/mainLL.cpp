#include <iostream>
#include "LinkListInt.cpp"
#include "LinkListChar.cpp"
#include "LinkListString.cpp"
#include "Polynomial.h"
#include <string>
#include <map>
using namespace std;

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
void move(NodeI* head){
  head = head->next;
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
  if(*LL==answer) cout<<"Test 3 Passed"<<endl;
  else cout<<"Test 3 Failed"<<endl;
}
void unitTestappend2()
{
  NodeI* LL = new NodeI();
  LL->append(7);
  NodeI* answer = new NodeI(7);
  if(*LL==answer) cout<<"Test 4 Passed"<<endl;
  else cout<<"Test 4 Failed"<<endl;
}
void unitTestInsertAt1(){
  int arr[6]={1,2,3,4,6,7};
  NodeI* LL = new NodeI(arr,6);
  LL->insertAt(5,4);
  int arr2[7] = {1,2,3,4,5,6,7};
  NodeI* answer = new NodeI(arr2,7);
  if(*LL==answer) cout<<"Test 5 Passed"<<endl;
  else cout<<"Test 5 Failed"<<endl;
}
void unitTestInsertAt2()
{
  NodeI* LL = new NodeI();
  LL->insertAt(7,0);
  NodeI* answer = new NodeI(7);
  if(*LL==answer) cout<<"Test 6 Passed"<<endl;
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
  if(*LL==answer) cout<<"Test 8 Passed"<<endl;
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
  if(*LL==answer) cout<<"Test 17 Passed"<<endl;
  else cout<<"Test 17 Failed"<<endl;
}
void unitTestDeleteVal2(){
  int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteVal(9);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI* answer = new NodeI(arr2,6);
  if(*LL==answer) cout<<"Test 23 Passed"<<endl;
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
  if(*LL==answer) cout<<"Test 18 Passed"<<endl;
  else cout<<"Test 18 Failed"<<endl;
}
void unitTestDeleteAt2()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteAt(-1);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI* answer = new NodeI(arr2,6);
  if(*LL==answer) cout<<"Test 19 Passed"<<endl;
  else cout<<"Test 19 Failed"<<endl;
}
void unitTestDeleteAt3()
{
 int arr[6] = {1,2,3,4,5,6};
  NodeI* LL = new NodeI(arr,6);
  LL->DeleteAt(10);
  int arr2[6] = {1,2,3,4,5,6};
  NodeI* answer = new NodeI(arr2,6);
  if(*LL==answer) cout<<"Test 20 Passed"<<endl;
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

NodeI* reverseList(NodeI* head) {
    NodeI* curr = head;
    NodeI* prev = nullptr;
    NodeI* next;
    while (curr != nullptr) {
        // Step 1: Store next
        next = curr->next;
        // Step 2: Reverse current node's next pointer
        curr->next = prev;
        // Step 3: Move pointers one position ahead
        prev = curr;
        curr = next;
    }
      // Return the head of reversed linked list
    return prev;
}

void badappend(NodeI* head, int val){ //memory leakage
  NodeI* nn = new NodeI(val);
  while(head->next != NULL){
    head = head->next;
  }
  head->next = nn;
}

int Length = 0;
string substring(string str, int start, int end){
  string sub = "";
  for(int i = start; i < end; i++){
    sub += str[i];
  }
  return sub;
}
NodePoly* stringToPoly(string s)
{
  bool negExp = false;
  NodePoly* Poly = NULL;
  int track = 0;
  bool expoCheck = false;
  bool NegCheck = false;
  string coe = "";
  string exp = "";
  int coei;
  int expi;
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == 'x')//when collecting the coefficent
    {
      coe = substring(s,track, i);// Step 1: take a substring from the beginning or operator to the x
      if(track != 0)
      {
        if(s[track-1] == '-')//if the operator is negative we will track that info
        {
          
          NegCheck = true;
        }
        else{
          NegCheck = false;
        }
      }
    }
    
    if(s[i] == '+' || s[i] == '-'|| i == s.length()-1)// the full exponent is over
    {
        
        if(s.length()-1 == i)//this part considers if the exponent is at the end
        {
          if(s[i] == 'x')
          {
            exp = "1";
          }
          else if(s[i] >= '0' && s[i-1] <= '9'){ //this may cause a bug
            exp = "0";
          }
          else
          {
            exp = substring(s,track, i+1);
          }
        }
        
        else if(s[i-1] == 'x')//when the exponent is 1
        {
          exp = "1";
        }
        else if(s[i-1] >= '0' && s[i-1] <= '9' && !expoCheck){//when the exponent is 0
          exp = "0";
        }
        else//when the exponent is bigger than 1
        {
          exp = substring(s,track, i);
        }
      coei = stoi(coe);//converting them into integers
      // if(negExp){
      //   expi = -1*stoi(exp);
      // }
      // else{
        expi = stoi(exp);
      // }
      
      if(NegCheck)//adding the negative to the coefficent if necessary
      {
        coei = -coei;
      }
      if(Poly == NULL)//creating the first term
      {
        Poly = new NodePoly(coei, expi);
      }
      else//adding another term
      {
        NodePoly *add = new NodePoly(coei, expi);
        Poly->append(add);

      }
      track = i+1;//moving tracker to start tracking the coeffiecent again
      negExp = false;
      expoCheck = false;
    }
    if(s[i] == '^')//when beginning to collect the exponent we reset the tracker to one past the upper
    {

      track = i+1;
      expoCheck = true;
      if(s[i+1] == '-'){
        i++;
        negExp = true;
      }
    }
  }
  return Poly;
}

NodePoly *AddPolynomials(string arr[],int len)
{
  NodePoly *PolyArr[len];
  for(int i = 0; i < len; i++)
  {
    // NodePoly *Poly = NULL;

    PolyArr[i] = stringToPoly(arr[i]);


  }
  int min = PolyArr[0]->exp;
  int max = PolyArr[0]->exp;

  for(int i = 0; i < len; i++)
  {
    NodePoly* temp = PolyArr[i];
    while(temp != NULL)
    {
      if(temp->exp < min)
      {
        min = temp->exp;
      }
      if(temp->exp > max)
      {
        max = temp->exp;

      }
      temp = temp->next;
    }
  }
  NodePoly *final = NULL;
  for(int i = max; i>=min;i--){
    int sum = 0;
    for(int j = 0; j < len; j++)
    {
      NodePoly *temp = PolyArr[j];
      while(temp != NULL)
      {
        if(temp->exp == i){
          sum += temp->coe;
        }
        temp = temp->next;
      }
    }
    if(sum != 0)
    {

      if(final == NULL){
        final = new NodePoly(sum,i);
      }
      else{
         final->append(new NodePoly(sum,i));
      }
      sum = 0;
    }
  }
  return final;
}
bool isin(NodeI *allCoes,int num){
  NodeI *temp = allCoes;
  while(temp != NULL){
    if(temp->data == num){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

NodePoly* simplify(NodePoly *Poly)
{
  int max = 0;
  int min = Poly->exp;
NodePoly* temp = Poly;
map<int,int> Mymap;
while(temp){
  if(min > temp->exp){
    min = temp->exp;
  }
  if(max < temp->exp){
    max = temp->exp;
  }

  if(Mymap.count(temp->exp)){
    Mymap[temp->exp]+=temp->coe;
  }
  else{
    Mymap[temp->exp] = temp->coe;
  }
  temp = temp->next;
}
NodePoly* answer = NULL;
for(int i = max;i >= min;i--){
  if(Mymap.count(i)){
    NodePoly* curr = new NodePoly(Mymap[i],i);
    if(!answer){
      answer = curr;
    }
    else{
      answer->append(curr);
    }
  }
}
return answer;
// int max = 0;
// NodePoly* temp = Poly;
// while(temp){
//   if(max < temp->exp){
//     max = temp->exp;
//   }
//   temp = temp->next;
// }
//   int arr[max+1];
//   for(int i = 0;i <= max;i++){
//     arr[i] = 0;
//   }
//   temp = Poly;
//   while(temp){
//     arr[temp->exp]+=temp->coe;
//     temp = temp->next;
//   }
//   NodePoly* answer = NULL;
//   for(int i = max; i > -1;i--){
//     if(arr[i]){
//       NodePoly* curr = new NodePoly(arr[i],i);
//       if(answer){
//         answer->append(curr);
//       }
//       else{
//         answer = curr;
//       }
      
//     }
//   }
//   return answer;

}
NodePoly *Multiply2(NodePoly *Poly2,NodePoly *Poly1){
  NodePoly *PolyF = NULL;
  NodePoly *temp1  = Poly1;
  while(temp1 != NULL)
  {
     NodePoly *temp2  = Poly2;
    while(temp2 != NULL)
    {
      NodePoly *term = new NodePoly(temp1->coe * temp2->coe, temp1->exp + temp2->exp);
      if(PolyF == NULL){
        PolyF = term;
      }
      else
      {
        PolyF->append(term);
      }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  PolyF = simplify(PolyF);
  return PolyF;
}

NodePoly *MultiplyPolynomials(string arr[], int Length)
{
  NodePoly *PolyArr[Length];
  for(int i = 0; i < Length; i++)
  {
    PolyArr[i] = stringToPoly(arr[i]);
  }
  NodePoly *answer = PolyArr[0];
  for(int i = 1; i < Length; i++)
  {
    answer = Multiply2(answer,PolyArr[i]);
  }
  return answer;
}

bool IsIn(NodeI* head, int target){
  if(head == NULL){
    return false;
  }
  else if(head->data == target){
    return true;
  }
  else{
    return IsIn(head->next, target);
  }
}








int main() 
{
  int arr[5] = {1,2,6,7,8};
  int arr1[3] = {3,4,5};
  NodeI* head = new NodeI(arr,5);
  NodeI* head2 = new NodeI(arr1,3);
  insertString(head,head2,2);
  head->prettyPrint();

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
