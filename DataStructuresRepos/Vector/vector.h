#include <iostream>
using namespace std;

int MAX_SIZE = 5;

class myString
{
private:
    char *arr;
    int size;

public:
    myString()
    {
        arr = new char[MAX_SIZE];
        size = 0;
    }
    bool isEmpty() // can make const
    {
        return !size;
    }
    void append(char val) // can throw err if size can't be increased anymore (size is at max int)
    {
        if (size % MAX_SIZE == 0)
        {
            char *nn = new char[size + MAX_SIZE];
            for (int i = 0; i < size; i++)
            {
                nn[i] = arr[i];
            }
            arr = nn;
        }
        arr[size] = val;
        size++;
    }
    void deleteAt(int index)
    {
        if(!isEmpty()){
            for(int i = index;i < size-1;i++){
                swap(arr[i],arr[i+1]);
            }
            size--;
        }
        
    }
    void erase(int start, int end) // throw err if is empty to ensure illegal process is found
    {
        if(start >= end || start >= size || end >= size){
            return;
        }
        for(int i = start;i < end;i++){
            
        }
    }
    char elementAt(int index) // can use operator[] for indexing // can make const
    {
        if (index < size && index > -1)
        {
            return arr[index];
        }
        else
        {
            return -1;
        }
    }
    int length() // can make const
    {
        return size;
    }
    void print() // can make const
    {
        if (isEmpty())
        {
            cout << "can't print. vector is empty" << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << arr[size - 1] << endl;
    }
};