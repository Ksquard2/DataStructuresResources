#include <iostream>
using namespace std;

class SLLQueue {
public:
    struct SLLQ {
        int data;
        SLLQ* next;
    };
    
    SLLQ* BOQ; // Beginning of the queue
    SLLQ* EOQ; // End of the queue
    int size;

    // Default constructor
    SLLQueue() {
        BOQ = NULL;
        EOQ = NULL;
        size = 0; // Fixed: remove 'int' keyword
    }

    // Enqueue a value
    void Enqueue(int val) {
        SLLQ* nn = new SLLQ(); // Allocate memory for a new node
        nn->data = val;
        nn->next = NULL; // New node points to NULL

        if (isEmpty()) {
            BOQ = nn; // Both BOQ and EOQ point to the new node
            EOQ = nn;
        } else {
            EOQ->next = nn; // Link the new node at the end
            EOQ = nn; // Update EOQ to the new node
        }
        size++;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void Deque() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            SLLQ* temp = BOQ; // Save the current BOQ
            BOQ = BOQ->next; // Move BOQ to the next node
            delete temp; // Free the memory of the dequeued node
            size--;
        }
    }

    void print() {
        cout << "Queue of size: " << size << endl;
        SLLQ* temp = BOQ;
        while (temp != NULL) { // Fixed: change to 'temp != NULL'
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
