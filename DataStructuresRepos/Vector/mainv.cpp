#include <iostream>
#include "vector.h"
#include <cmath>
using namespace std;

int main(){
    myString vec;
    for(int i = 0;i < 5;i++){
        int random_number = rand() % 25 + 1; 
        char rand = 'A'+random_number;
        vec.pushBack(rand);
    }
    vec.print();
    cout<<vec.elementAt(3)<<endl;
    vec.popBack();
    vec.popBack();
    vec.popBack();
    vec.popBack();
    vec.popBack();
    vec.popBack();
    vec.print();
}