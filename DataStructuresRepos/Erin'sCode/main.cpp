#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// bool allEqual(vector<int> v){
//     int start  = v[0];
//     for(int i = 0;i < v.size();i++){
//         if(start != v[i]){
//             return false;
//         }
//     }
//     return true;
// }
// void printV(vector<int> v){
//     for(int i = 0;i < v.size();i++){
//         if(i == v.size()-1){
//             cout<<v[i];
//         }
//         else{
//             cout<<v[i]<<", ";
//         }
//     }
//     cout<<endl;
// }

// int trafficLights(int num, vector<vector<int>> lights){
//     vector<int> start;
//     vector<int> rates;
//     for(int i = 0;i < lights.size();i++){
//         if(lights[i][1] == 1){
//             start.push_back(lights[i][0]);
//         }
//         else{
//             start.push_back(lights[i][0]+1);
//         }
//         rates.push_back(lights[i][0]+lights[i][1]);
//     }
//     while(!allEqual(start)){
//         for(int i = 0;i < start.size();i++){
//             start[i]+=rates[i];
//         }
//     }
//     return start[0];
// }
// vector<int> sequence(vector<int> v){
//     int start = 0;
//     while(v[start] == 0){
//         start++;
//     }
//     int end = start+1;
//     while(v[end] == 0){
//         end++;
//     }
//     int rate = (v[end]-v[start])/(end-start);
//     int sValue = v[start];
//     int trueStart = start;
//     while(trueStart){
//         sValue-=rate;
//         trueStart--;
//     }
//     for(int i = 0;i < v.size();i++){
//         v[i] = sValue;
//         sValue+=rate;
//     }
//     return v;
// }

// int lcm(vector<int> v){
//     int product = 0;
//     for(int i = 0;i < v.size();i++){
//         product*=v[i];
//     }
// }

// int sumation(int num){
//     num++;
//     return ((num*num)-num)/2;
// }
char* substring(char* str,int start,int end){
    str[end] = '\0';
    return &str[start];
}
int main(int argc, char **argv){

    string first = "base";
    string last = "ball";
    string full = first + last;

    
}


