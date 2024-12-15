#include <iostream>
#include <cstring>
#include <set>
using namespace std;
void PathRecursionS(int i, int j, int k, set<string>& printed)
{
  if(k > 0)
  {

string parent = "R("+to_string(i)+","+to_string(j)+","+to_string(k)+")";
    string t1 = "R("+to_string(i)+","+to_string(j)+","+to_string(k-1)+")";
    string t2 = "R("+to_string(i)+","+to_string(k)+","+to_string(k-1)+")";
    string t3 = "R("+to_string(k)+","+to_string(k)+","+to_string(k-1)+")";
    string t4 = "R("+to_string(k)+","+to_string(j)+","+to_string(k-1)+")";
    if(printed.find(parent) == printed.end())
    {
      cout<<parent<<" = "<<t1<<" U "<<t2<<t3<<"*"<<t4<<endl<<endl;
      printed.insert(parent);
    }
    PathRecursionS(i,j,k-1,printed);
    PathRecursionS(i,k,k-1,printed);
    PathRecursionS(k,k,k-1,printed);
    PathRecursionS(k,j,k-1,printed);
  }
  
    
}
int main()
{
  
  set<string> printed;
  PathRecursionS(1, 8, 8, printed);
}