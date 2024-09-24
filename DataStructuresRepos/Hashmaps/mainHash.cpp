#include <iostream>
#include "LinkPair.cpp"
#include "Hashmap.cpp"
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() 
{
  // NodeS* list = new NodeS("hello");
  // list->appendC("meep");
  // list->prettyPrint();
  // map<string, NodeS*> teams;
  // for(int i = 0;i<2;i++){
  //   string name;
  //   string number;
  //   cout<<"Players name: ";
  //   cin>>name;
  //   cout<<"Players number: ";
  //   cin>>number;
  //   teams.insert(pair<string, string>(name,number));
  // }
  // string curr;
  Hashtable ht;
  ht.insertItem(905, "Sophie");
  ht.insertItem(603, "George");
  ht.insertItem(802, "Corry");
  ht.insertItem(105, "David");

  ht.printTable();
  return 0;
};