#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "LinkPair.cpp"
#include <cstring>

//Phonebook class 905, Name
using namespace std;

class Hashtable {
  private:
    static const int hashGroups = 10;
    NodePair *table[hashGroups];
  public:
    Hashtable()
    {
      for(int i = 0; i < hashGroups; i++)
      {
        table[i] = nullptr;
      }
    }
    
    bool isEmpty()
    {
      
      for(int i = 0; i < hashGroups; i++)
      {
        if(table[i] != nullptr)
        {
          return false;
        }
      }
      return true;
    }

    int hashFunction(int key)
    {
      return key % hashGroups;
    }
    void insertItem(int key, string name)
    {
      int hashValue = hashFunction(key);
      NodePair *ptr = new NodePair(key, name);
      
      if(table[hashValue] == nullptr)
      {
        table[hashValue] = ptr;
       
      }
      else
      {
        NodePair *temp = table[hashValue];
        while(temp->next != nullptr)
        {
          temp = temp->next;
        }
        temp->next = ptr;
      }
    }
    void removeItem(int key)
    {
      int hashValue = hashFunction(key);
      NodePair *temp = table[hashValue];
      NodePair *prev = nullptr;
      if(temp != nullptr && temp->key == key)
      {
        table[hashValue] = temp->next;
        delete temp;
      }
      else
      {
        while(temp != nullptr && temp->key != key)
        {
          prev = temp;
          temp = temp->next;
        }
      }
    }
    string searchItem(int key)
    {
      int hashValue = hashFunction(key);
      NodePair *temp = table[hashValue];
      if(temp == nullptr)
      {
        return "Not Found";
      }
      else
      {
        while(temp != nullptr)
        {
          if(temp->key == key)
          {
            return temp->val;
          }
        }
      }
        return "";
    }
    void printTable()
    {
     
      for(int i =0; i < hashGroups; i++)
      {
        if(table[i] != nullptr)
        {
          cout << i<< ": " << table[i]->key << "[" << table[i]->val << "] ";
          while(table[i]->next != nullptr)
          {
            table[i] = table[i]->next;
            cout << table[i]->key << "[" << table[i]->val << "] ";
          }
          cout<<endl;
        }
        
        
        
      }
    }
};

#endif