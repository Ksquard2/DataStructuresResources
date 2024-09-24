#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class town{
  public:
  string name;
  int pop;
  string mayor;
  town();

  town(string n, int p, string m){
    name = n;
    pop=p;
    mayor = m;
  }
  int operator+(const town& t){
    return pop + t.pop;
  }
  ostream& operator<<(ostream& out){
    out << name;
    return out;
  }
  void printClass(){
    cout<<" is the mayor of "<<name<<" with a population of "<<pop;
  }
};
int main() 
{

  town t = town("mainstreet", 30,"ahmed");
  town a = town("peepstreet", 20,"bamed");
  town b = town("meatstreet", 20,"locmed");
  town meep[3] = {t,a,b};
  map<string,town> myMap;
  string arr[3] = {"mainstreet","peepstreet","meatstreet"};
  myMap[t.name] = t;
  myMap[a.name] = a;
  myMap[b.name] = b;
  myMap[arr[0]].printClass();
  // for(int i = 0;i < 3;i++)
  // {
  //   myMap[arr[i]].printClass();
  //   cout<<endl;
  // }
//   myMap["kevin"] = 123;
//   myMap["george"] = 123;
//   myMap["bob"] = 123;
  
//   for(const auto& element :myMap){
//     cout<<element.first<<" : "<<element.second<<endl; 
//   }

//   myMap.erase("bob");
//   for(const auto& element :myMap){
//     cout<<element.first<<" : "<<element.second<<endl; 
//   }
//   auto b = myMap.find("kevin");
//   if(b == myMap.end()){
//     cout<<"Not Found";
//   }
//   else{
//     cout<<"Found"<<endl;
//   }

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
  // Hashtable ht;
  // ht.insertItem(905, "Sophie");
  // ht.insertItem(603, "George");
  // ht.insertItem(802, "Corry");
  // ht.insertItem(105, "David");

  // ht.printTable();
  // return 0;
};