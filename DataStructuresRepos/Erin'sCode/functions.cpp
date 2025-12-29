#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void equal(int array[],int size,int eq)
{
    for(int i = 0; i < size,i++;){
        array[i] = eq;}
}

int main(){
    int num[10] = {0,0,0,15,0,3,0,0,0,0};
    int i = 0,a = 0,b = 0;
    int x,y;

    while (i)
    {
        if(num[i] != 0 && a == 0)
        {
           a = i;

        }
        else if (num[i] != 0 && b == 0)
        {
            b = i;
            return;
        }
        i++;
    }

     x = num[b] - num[a];
     y = b - a;        
    
    if(y==x)
    
}