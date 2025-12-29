#include <iostream>
#include <vector>
using namespace std;

int max(int val1,int val2){
    return (val1>val2) ? val1 : val2;
}
int sub(const vector<int>& v, int index, vector<int>& memo){
    if(memo[index] != -1){
        return memo[index];
    }
    int best = 1;
    for(int j = index+1;j < v.size();j++){
        if(v[index] < v[j]){
            best = max(best,1+sub(v,j,memo));
        }
    }
    return memo[index] = best;
}
int LSS(vector<int> v){
    int longest = 0;
    vector<int> memo(v.size(), -1);
    int best = 0;
    int curr = 0;
    for(int i = 0 ;i <v.size();i++){
        curr = sub(v, i, memo);
        best = max(best,curr);
    }
    return best; 
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(8);
    v.push_back(2);
    v.push_back(5);
    vector<int> memo(v.size(), -1); // create after v is built
    cout << LSS(v) << "\n";
}
