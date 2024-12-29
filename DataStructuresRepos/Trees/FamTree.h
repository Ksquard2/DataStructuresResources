#include <iostream>
using namespace std;
#include <vector>
#include <queue>

struct Kiel{
    string name;
    string bio;
    string spouse;
    bool leaf = true;
    vector<Kiel*> child;
};

void insertChild(Kiel* head, string parent, string n){
            if(parent == "OG"){
                head->name = n;
            }
            if(head->name == parent){
                head->leaf = false;
                Kiel* c = new Kiel;
                c->name = n;
                head->child.push_back(c);
            }
            else if(!head->leaf){
                for(int i = 0;i < head->child.size();i++){
                    insertChild(head->child[i],parent,n);
                }
            }
    }

 vector<vector<Kiel*> > levelOrderFam(Kiel* root) {
        
        queue<Kiel*> q;
        vector<vector<Kiel*> > lorder;
        if(!root) {
            return lorder;
        }
        q.push(root);
        while(!q.empty()){ // 3
            vector<Kiel*> checker; 
            int qSize = q.size();
            for(int i =0; i < qSize; i++){// 1                TreeNode* curr = q.front();
                Kiel* curr = q.front();
                q.pop();
                checker.push_back(curr);
                for(int i = 0;i < curr->child.size();i++){
                  q.push(curr->child[i]);
                }
            }
            lorder.push_back(checker);  
        }
       return lorder;
     }
void printFam(Kiel* root){
    vector<vector<Kiel*> > fam = levelOrderFam(root);
    for(int i = 0;i < fam.size();i++){
      cout<<"Generation "<<i+1<<" : ";
      for(int j = 0;j < fam[i].size();j++){
        if(j != fam[i].size()-1){
          cout<<fam[i][j]->name<<", ";
        }
        else{
          cout<<fam[i][j]->name;
        }
        
      }
      cout<<endl;
    }
}

