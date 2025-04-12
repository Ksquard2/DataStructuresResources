#include <iostream>
using namespace std;

string subString(string str,int start, int end);
int cti(char i);
int STI(string s);
double STF(string s);
class DNode{
    public:
    int datai;
    string datas;
    double datad;
    char datac;
    DNode* next;
    DNode();
    void setVal(string type,string data){
        if(type == "string"){
            datas = data;
        }
        else if(type == "double"){
           datad = STF(data);
        }
        else if(type == "int"){
            datai = STI(data);
        }
        else{
            datac = data[0];
        }
    }
};

class DLList{
    private:
    DNode* head;
    int size;
    string type;
    public:
    DLList(string t){
        head = NULL;
        size = 0;
        type = t;
    }
    void insertAt(string val,int index){
        DNode* nn = new DNode();
        nn->setVal(type, val);
        if(!head){
            head = nn;
        }
        else if(!index){
            nn->next = head;
        }
        else{
            DNode* temp = head;
            while(temp){
                if(index == 1){
                    nn->next = temp->next;
                    temp->next = nn;
                    return;
                }
                temp = temp->next;
                index--;
            }
            cout<<"index too big!";
        }
    }
    void deleteAt(int index){
        if(!index){
            head = head->next;
        }
        else{
            DNode* curr = head;
            DNode* prev = NULL;
            while(curr->next)
            {
                prev = curr;
                curr = curr->next;
                index--;
                if(index == 1)
                {
                    prev->next = curr->next;
                    DNode* temp = curr;
                    curr->next = NULL;
                    delete(curr);
                }
            }
        }
    }
    
};
string subString(string str,int start, int end){
    string nn = "";
    for(int i = start;i < end;i++){
      nn+=str[i];
    }
    return nn;
  }
int cti(char i)
{
  i = tolower(i);
  return i - '0';
}

int STI(string s)
{
    int c = 0;
    int meme = 1;
    for(int i = s.length()-1;i > -1; i--)
    {
        int v = cti(s[i])*(meme);
        c = c+v;
        meme = meme*10;
    }
    return c;
}

double STF(string s){
    int tracker = 0;
    while(s[tracker] != '.'){
        tracker++;
    }
    double x = double(STI(subString(s,0,tracker)));
    double q = 1;
    for(int i = 0;i < s.length()-tracker-1;i++){
        q*=10.0;
    }
    double y = double(STI(subString(s,tracker+1,s.length())))/q;
    double sum = x+y;
    return sum;
}