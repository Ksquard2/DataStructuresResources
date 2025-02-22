#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double e(double po)
{

    double e_approx = 1.0;
    double factorial = 1.0;
    for (int i = 1; i < 20; ++i)
    {
        factorial *= i;
        e_approx += 1.0 / factorial;
    }
    return pow(e_approx, po);
}
double sumE(int index)
{
    double result = 0.0;
    for (int i = 1; i <= index; i++)
    {
        result += e(i);
    }
    return result;
}
double softMax(vector<double> i, vector<double> w, int one, int two)
{
    double hall = e(-1.0*( (w[one]*i[one]) + (w[two]*i[two]) ));
    double result = 1.0/(1.0+hall);
    return result;
}
double sigmoid(double x)
{
    double answer = 1.0 / (1.0 + e(x * -1.0));
    return answer;
}
void forwardProp(double start, vector<double> weights, vector<double> bias)
{
    vector<double> answer;
    cout << "input layer: " << start << endl;
    for (int i = 0; i < weights.size(); i++)
    {
        start *= weights[i];
        start += bias[i];
        cout << "pre sigmoid: " << start << endl;
        start = sigmoid(start);
        cout << "post sigmoid: " << start << endl;
    }
    double y = start - .9;
    double loss = (y * y) / 2;
    cout << "Loss: " << loss << endl;
}

int singleMult(vector<int> matrix1, vector<vector<int> > matrix2, int col)
{
    int sum = 0;
    for (int i = 0; i < matrix1.size(); i++)
    {
        sum += (matrix1[i] * matrix2[i][col]);
    }
    return sum;
}

double singleMult3(vector<double> matrix1, vector<vector<double> > matrix2, int col)
{
    double sum = 0;
    for (int i = 0; i < matrix1.size(); i++)
    {
        sum += (matrix1[i] * matrix2[i][col]);
    }
    return sum;
}

double vectorMult(vector<double> matrix1, vector<double> matrix2, int start, double bias)
{
    double sum = 0.0;
    for (int i = 0; i < matrix1.size(); i++)
    {
        if(i != matrix1.size()-1)
        {
            sum += (matrix1[i] * matrix2[i+start]);
        }
        else 
        {
            sum += (matrix1[i] * matrix2[i+start]) + bias;
        }
    }
    return sum;
}
vector<vector<double> > divide(vector<vector<int> > matrix, bool left,bool upper){
    vector<vector<double> > result;
    vector<double> add;
    int startc;
    int startr;
    int endc;
    int endr;
    if(left){
        startc = 0;
        endc = matrix[0].size()/2;
    }
    else{
        startc = matrix[0].size()/2;
        endc = matrix[0].size();
    }
    if(upper){
        startr = 0;
        endr = matrix.size()/2;
    }
    else{
        startr = matrix.size()/2;
        endr = matrix.size();
    }

    for(int i = startr; i < endr;i++)
    {
        for(int j = startc;j < endc;j++)
        {
            add.push_back(matrix[i][j]);
        }
        result.push_back(add);
        add.clear();
    }
    return result;
}
vector<vector<double> > matrixMulti3(vector<vector<double> > matrix1, vector<vector<double> > matrix2)
{
    vector<vector<double> > answer;
    for (int i = 0; i < matrix1.size(); i++)
    {
        vector<double> v;
        for (int j = 0; j < matrix1.size(); j++)
        {
            int sum = singleMult3(matrix1[i], matrix2, j);
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}
vector<vector<double> > finalMult(vector<vector<double> > matrix1, vector<vector<double> > matrix2){

}

vector<vector<int> > matrixMulti(vector<vector<int> > matrix1, vector<vector<int> > matrix2)
{
    vector<vector<int> > answer;
    for (int i = 0; i < matrix1.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < matrix1.size(); j++)
        {
            int sum = singleMult(matrix1[i], matrix2, j);
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}

void printMatrix(vector<vector<int> > matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
vector<double> forwardProp2(vector<double> input, vector<double> weights, vector<double> bias, int col = 1)
{   int hr;
    //find the number of rows for the hidden layer
    if(col-1){
        int quad = pow((2*input.size()),2) + 4*(col-1)*weights.size();
        hr = (sqrt(quad) - 2*input.size())/(2*col-1);
    }
    else{
        hr = weights.size()/(input.size()*2);
    }
    int last = input.size()*hr;

    vector<double> hidden;
    int inc = input.size();
    bool exp = false;
    //index for bias vector
    int bindex = 0;
    //loops through the weights vector incrementing based on the number of values in the hidden layer
    for(int i = 0; i < weights.size(); i = i + inc) 
    {
        if(exp){
            inc = input.size();
        }
        double val = 0.0;
        //1. vector multiplication
        val = vectorMult(input,weights,i,bias[bindex]);
        //2. adds a product of vectors into temporary hidden layer vector
        hidden.push_back(sigmoid(val));
        //3. check if hidden layer is complete
        if(hidden.size() == hr)
        {
            //4. hidden layer vector becomes new input vector
            input = hidden;
            for(int i = 0;i < hidden.size();i++){
                cout<< i+1<<": "<<hidden[i]<<" ";
            }
            hidden.clear();
            //5. observe the next bias
            bindex++;
            exp = true;
            cout<<endl;
        }
        //6. check if we have reached the output layer
        if(i + last + 1 == weights.size()){
            hr = last/hr;
        }
    }
    return input;
}

bool isEven(int num){
    if(num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Function to add two matrices

vector<vector<int> > operator+(const vector<vector<int> > &A, const vector<vector<int> > &B) {
    int n = A.size();
    vector<vector<int> > C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices

vector<vector<int> > operator-(const vector<vector<int> > &A, const vector<vector<int> > &B) {
    int n = A.size();
    vector<vector<int> > C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Function to perform matrix multiplication using Divide and Conquer
vector<vector<int> > multiply(const vector<vector<int> > &A, const vector<vector<int> > &B) {
    int n = A.size();
    vector<vector<int> > C(n, vector<int>(n, 0));

    // Base case: If matrix size is 1x1, perform scalar multiplication
    if (n == 2) {
        C = matrixMulti(A,B);
        return C;
    }

    // Split matrices into four submatrices
    int newSize = n / 2;
    vector<vector<int> > A11(newSize, vector<int>(newSize, 0));
    vector<vector<int> > A12(newSize, vector<int>(newSize, 0));
    vector<vector<int> > A21(newSize, vector<int>(newSize, 0));
    vector<vector<int> > A22(newSize, vector<int>(newSize, 0));
    vector<vector<int> > B11(newSize, vector<int>(newSize, 0));
    vector<vector<int> > B12(newSize, vector<int>(newSize, 0));
    vector<vector<int> > B21(newSize, vector<int>(newSize, 0));
    vector<vector<int> > B22(newSize, vector<int>(newSize, 0));

    // Fill submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    // vector<vector<int> > P = multiply(A11+A12,B11+B12);
    // vector<vector<int> > Q = multiply(A21+A22,B11);
    // vector<vector<int> > R = multiply(A11,B12-B22);
    // vector<vector<int> > S = multiply(A22,B21-B11);
    // vector<vector<int> > T = multiply(A11+A12,B22);
    // vector<vector<int> > U = multiply(A21-A11,B11-B12); 
    // vector<vector<int> > V = multiply(A12-A22,B21+B22);

    // Recursive multiplication of submatrices
    // vector<vector<int> > C11 = P+S-T+V;
    // vector<vector<int> > C12 = R+T;
    // vector<vector<int> > C21 = Q+S;
    // vector<vector<int> > C22 = P+R-Q+U;
    vector<vector<int> > C11 = multiply(A11, B11)+multiply(A12, B21);
    vector<vector<int> > C12 = multiply(A11, B12)+multiply(A12, B22);
    vector<vector<int> > C21 = multiply(A21, B11)+multiply(A22, B21);
    vector<vector<int> > C22 = multiply(A21, B12)+multiply(A22, B22);
    // Combine results into final matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    return C;
}



int main()
{
    // for(int i = 0;i < 32;i++){
    //     for(int j = 0;j < 32;j++){
    //         cout<<"*";
    //         if((j+1)%4 == 0){
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    //     if((i+1)%4==0){
    //         cout<<endl;
    //     }
    // }
//   int n = 4; // Ensure n is a power of 2 for simplicity
//     vector<vector<int> > A;
//     vector<vector<int> > B;
//     vector<int> input;
//     for(int i = 1;i <= 16;i++){
//         int random_number = rand() % 9 + 1; 
//         input.push_back(random_number);
//         if(i%4 == 0){
//             A.push_back(input);
//             input.clear();
//         }
//     }
//     for(int i = 1;i <= 16;i++){
//         int random_number = rand() % 9 + 1; 
//         input.push_back(random_number);
//         if(i%4 == 0){
//             B.push_back(input);
//             input.clear();
//         }
//     }
//     cout << "Matrix A:" << endl;
//     printMatrix(A);
//     cout << "\nMatrix B:" << endl;
//     printMatrix(B);

//     vector<vector<int> > C = multiply(A, B);
//     vector<vector<int> > D = matrixMulti(A,B);
   
//     cout << "\nResultant Matrix C (A * B):" << endl;
//     printMatrix(C);
//     cout<<endl;
//     printMatrix(D);
vector<double> w;
double start = .3;
vector<double> b;
w.push_back(.5);
w.push_back(.2);
b.push_back(.3);
b.push_back(.4);
forwardProp(start,w,b);
    // vector<double> bias;
    // bias.push_back(.35);
    // bias.push_back(.6);
    // vector<double> input;
    // input.push_back(.5);
    // input.push_back(.1);
    // vector<double> weights;
    // weights.push_back(.15);
    // weights.push_back(.2);
    // weights.push_back(.25);
    // weights.push_back(.3);
    // weights.push_back(.4);
    // weights.push_back(.45);
    // weights.push_back(.5);
    // weights.push_back(.55);
    // forwardProp2(input, weights,bias);

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