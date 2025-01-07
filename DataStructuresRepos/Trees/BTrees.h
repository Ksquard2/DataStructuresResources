#include <iostream>
using namespace std;

struct Node {
    int keys[4] = {-1, -1, -1, -1}; // 4 keys max
    Node* pointers[5] = {NULL, NULL, NULL, NULL, NULL}; // 5 children max
    bool leaf; // Is it a leaf node?
};

class bTrees {
public:
    Node* root;
    
    bTrees() {
        root = new Node();
        root->leaf = true;
    }

    // Function to find the index to insert a key in a node
    int findKey(Node* node, int key) {
        int idx = 0;
        while (idx < 4 && node->keys[idx] != -1 && node->keys[idx] < key) {
            idx++;
        }
        return idx;
    }

    // Function to split a full child node
    void splitChild(int idx, Node* parent, Node* child) {
        Node* newChild = new Node();
        newChild->leaf = child->leaf;
        
        // Move the last two keys from child to newChild
        newChild->keys[0] = child->keys[2];
        newChild->keys[1] = child->keys[3];
        child->keys[2] = -1;
        child->keys[3] = -1;
        
        // Move pointers to the new child
        if (!child->leaf) {
            newChild->pointers[0] = child->pointers[3];
            newChild->pointers[1] = child->pointers[4];
            child->pointers[3] = child->pointers[4] = NULL;
        }
        
        // Shift the pointers in the parent to make room for the new child
        for (int i = 3; i >= idx + 1; i--) {
            parent->pointers[i + 1] = parent->pointers[i];
        }
        
        // Insert the new child pointer and the middle key in the parent
        parent->pointers[idx + 1] = newChild;
        for (int i = 2; i >= idx; i--) {
            parent->keys[i + 1] = parent->keys[i];
        }
        
        parent->keys[idx] = child->keys[1];
        child->keys[1] = -1;
    }

    // Function to insert a key in a non-full node
    void insertNonFull(Node* node, int key) {
        int idx = findKey(node, key);
        
        if (node->leaf) {
            // Insert the key in the leaf node (sorted)
            for (int i = 3; i >= idx; i--) {
                node->keys[i + 1] = node->keys[i];
            }
            node->keys[idx] = key;
        } else {
            // Recur into the appropriate child
            Node* child = node->pointers[idx];
            
            if (child->keys[3] != -1) {
                // The child is full, so split it
                splitChild(idx, node, child);
                
                // After split, the middle key will be pushed up
                if (key > node->keys[idx]) {
                    idx++;
                }
            }
            insertNonFull(node->pointers[idx], key); // Recurse into the appropriate child
        }
    }

    // Function to insert a key into the B-tree
    void insert(int key) {
        // If the root is full, split it
        if (root->keys[3] != -1) {
            Node* newRoot = new Node();
            newRoot->leaf = false;
            newRoot->pointers[0] = root;
            
            // Split the old root and push the middle key to the new root
            splitChild(0, newRoot, root);
            
            // New root might need to be adjusted
            root = newRoot;
        }
        
        // Insert the key into the non-full root
        insertNonFull(root, key);
    }
    bool isIn(Node* c, int x){
        for(int i = 0;i < 4;i++){
            if(!c){
                cout<<x<<" is not in the tree."<<endl;
                return false;
            }
            if(c->keys[i] == x){
                cout<<x<<" is in the tree."<<endl;
                return true;
            }
            if(!c->leaf){
                if(c->keys[i] > x){
                    return isIn(c->pointers[i],x);
                }
                else if(c->keys[i] < x && i == 3){
                    return isIn(c->pointers[i+1],x);
                }
            }
            else{
                if(c->keys[i] == -1){
                    cout<<x<<" is not in the tree."<<endl;
                    return false;
                }
            }
        }
    }

    // Helper function to print the tree (for debugging)
    void print(Node* node, int level = 0) {
        if (node == nullptr) return;
        
        cout << "Level " << level << ": ";
        for (int i = 0; i < 4 && node->keys[i] != -1; i++) {
            cout << node->keys[i] << " ";
        }
        cout << endl;
        
        if (!node->leaf) {
            for (int i = 0; i < 5; i++) {
                print(node->pointers[i], level + 1);
            }
        }
    }
};

// Test the B-tree class
