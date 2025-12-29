#include <iostream>
#include "vector.h"
#include <cmath>
using namespace std;

int main(){
    myString vec;
    for(int i = 0;i < 20;i++){
        char random_char = 'A' + rand() % 26; 
        vec+=random_char;
    }
    for(int i = 0;i < 20;i++){
        cout<<vec[i];
    }
}


