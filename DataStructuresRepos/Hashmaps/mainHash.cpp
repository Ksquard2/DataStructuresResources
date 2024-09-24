#include <iostream>
#include "LinkPair.cpp"
#include "Hashmap.cpp"
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() 
{
  Hashtable ht;
  ht.insertItem(905, "Sophie");
  ht.insertItem(603, "George");
  ht.insertItem(802, "Corry");
  ht.insertItem(105, "David");

  ht.printTable();
  return 0;
};