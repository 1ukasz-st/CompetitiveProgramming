#include <iostream>

class IntStack {
private:
    struct Node {
        int data;
        Node* prev;
        Node(int val) : data(val), prev(nullptr) {}
    };

    Node* topNode;

public:
    IntStack() : topNode(nullptr) {}

    ~IntStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push an integer onto the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->prev = topNode;
        topNode = newNode;
    }

    // Pop the top integer from the stack
    void pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->prev;
            delete temp;
        }
    }

    // Get the top integer from the stack without removing it
    int top() const {
        if (!isEmpty()) {
            return topNode->data;
        } else {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can handle this error differently if needed
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topNode == nullptr;
    }
};