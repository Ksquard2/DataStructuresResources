#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

using namespace std;

class NodePair {
public:
  int key;
  string val;
  NodePair *next;
  int size = 0;

  // Default constructor
  NodePair() {
    val = "";
    key = 0;
    next = NULL;
  }

  // Parameterised Constructor
  NodePair(int I, string S) {
    val = S;
    key = I;
    next = NULL;
  }
  NodePair(NodePair *n) {
    key = n->key;
    val = n->val;
    next = NULL;
  }
};

#endif