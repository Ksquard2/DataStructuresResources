#include <iostream>
#include <math.h>
using namespace std;

class QHash {
    public:
    int map[10];
    QHash(){
        for(int i = 0;i < 10;i++){
            map[i] = -1;
        }
    }

    void printHash(){
        for(int i = 0;i < 10;i++){
            if(map[i] != -1){
                cout<<map[i]<<"("<<i<<") ";
            }
            
        }
        cout<<endl;
    }
    void insertHelper(int x, int index, int coll = 0){

        if(map[index] == -1){
            map[index] = x;
        }
        else if(coll <= 30){
            coll++;
            index = (x%10 + int(pow(coll,2)))%10;
            insertHelper(x,index,coll);
        }
        else{
            cout<<x<<" can not be inserted"<<endl;
        }
    }
    void insert(int x){
        insertHelper(x,x%10);
        printHash();
    }
    void DELETE(int key){
        map[key] = -1;
    }
};