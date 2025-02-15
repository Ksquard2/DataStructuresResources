#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



double e(double po){
    
    double e_approx = 1.0;
    double factorial = 1.0;
    for (int i = 1; i < 20; ++i) {
        factorial *= i;
        e_approx += 1.0 / factorial;
    }
    return pow(e_approx, po);
}
double sumE(int index){
    double result = 0.0;
    for(int i = 1; i <= index;i++){
        result+=e(i);
    }
    return result;
}
double softMax(double exp){
  
}
double sigmoid(double x){
    double answer = 1.0/(1.0+e(x*-1.0));
    return answer;
}
void forwardProp(double start, vector<double> weights,vector<double> bias)
{
    vector<double> answer;
    cout<<"input layer: "<<start<<endl;
    for(int i = 0;i < weights.size();i++){
        start*=weights[i];
        start+=bias[i];
        cout<<"pre sigmoid: "<<start<<endl;
        start = sigmoid(start);
        cout<<"post sigmoid: "<<start<<endl;
    }
    double y = start - .9;
    double loss = (y*y)/2;
    cout<<"Loss: "<<loss<<endl;
}

int singleMult(vector<int> matrix1,vector<vector<int> > matrix2,int col){
    int sum = 0;
    for(int i = 0;i < matrix1.size();i++)
    {
        sum+=(matrix1[i]*matrix2[i][col]);
    }
    return sum;
}

vector<vector<int> > matrixMulti(vector<vector<int> >matrix1, vector<vector<int> > matrix2){
    vector<vector<int> > answer;
    for(int i = 0;i < matrix1.size();i++){
        vector<int> v;
        for(int j = 0;j < matrix1.size();j++){
            int sum = singleMult(matrix1[i],matrix2,j);
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}
void printMatrix(vector<vector<int> >matrix){
    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
vector<double> forwardProp2(vector<double> start, vector<double> weights)
{
    vector<double> hidden;
    double val = 0.0;
    for(int i = 0;i < weights.size();i=i+start.size()){
        for(int j = 0;j < start.size();j++){
            val+=(start[j]*weights[j+i]);
        }
        cout<<"Value: "<<val<<endl;
        hidden.push_back(val);
        val = 0.0;
        if(hidden.size() == start.size()){
            start = hidden;
            cout<<hidden[0]<<endl<<hidden[1]<<endl;
            hidden.clear();
        }
    }
    return start;
}
int main()
{
    vector<double> start;
    start.push_back(.5);
    start.push_back(.1);
    vector<double> weights;
    weights.push_back(.15);
    weights.push_back(.2);
    weights.push_back(.25);
    weights.push_back(.3);
    weights.push_back(.4);
    weights.push_back(.45);
    weights.push_back(.5);
    weights.push_back(.55);
    forwardProp2(start,weights);
















    
// cout << "Approximation of e: " << e_approx << endl;
// vector<int> line1;
// line1.push_back(3);
// line1.push_back(5);
// line1.push_back(1);
// vector<vector<int> > m1;
// m1.push_back(line1);
// m1.push_back(line1);
// vector<int> line;
// vector<vector<int> > m2;
// line.push_back(2);
// line.push_back(4);
// m2.push_back(line);
// m2.push_back(line);
// m2.push_back(line);
// cout<<"Matrix 1: "<<endl;
// printMatrix(m1);
// cout<<"Matrix 2: "<<endl;
// printMatrix(m2);
// cout<<"Matrix Multiplication: "<<endl;
// printMatrix(matrixMulti(m1,m2));
}