#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class town {
public:
    string name;
    int pop;
    string mayor;
    town() {}
    town(string n, int p, string m) : name(n), pop(p), mayor(m) {}
    int operator+(const town& t) {
        return pop + t.pop;
    }
    friend ostream& operator<<(ostream& out, const town& t) {
        out << t.name;
        return out;
    }
    void printClass() {
        cout << mayor << " is the mayor of " << name << " with a population of " << pop << endl;
    }
};

int main() {
    town t("mainstreet", 30, "ahmed");
    town a("peepstreet", 20, "bamed");
    town b("meatstreet", 20, "locmed");

    map<string, town> myMap;
    myMap[t.name] = t;
    myMap[a.name] = a;
    myMap[b.name] = b;

    // Using the printClass method
    myMap["mainstreet"].printClass();  // Outputs: is the mayor of mainstreet with a population of 30
    myMap["peepstreet"].printClass(); 
    myMap["meatstreet"].printClass(); 

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
  // return 0;
};