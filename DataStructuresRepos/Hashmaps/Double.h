#include <iostream>
#include <math.h>
using namespace std;

class DHash{
    private:
        int hashVar;
        int map[10];
    public:

        DHash(int hv){
            for(int i = 0;i < 10;i++){
                map[i] = -1;
            }
            hashVar = hv;
        }
        void printHash(){
            for(int i = 0;i < 10;i++){
                if(map[i] != -1){
                    cout<<map[i]<<"("<<i<<") ";
                }
            }
            cout<<endl;
        }
        void insertHelper(int x, int index,int coll = 0){
            if(map[index] == -1){
                cout<<"Collisions("<<x<<"): "<<coll<<endl;
                map[index] = x;
            }
            else if(coll <= 30)
            {
                coll++;
                index = (x%10 + coll*(hashVar-(x%hashVar)))%10;
                
                // index = (x + coll*(hashVar-(x%hashVar)))%10;

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
};