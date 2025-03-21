/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-24.  
           
  TIME: 6:14 PM.
*/
#include <iostream>
using namespace std;

// A class to represent a node of the linked list
class Node {
public:
    int data;
    Node* next;
};

// Stack using linked list
class StackLinkedList {
private:
    Node* top; // Pointer to the top element

public:
    // Constructor to initialize stack
    StackLinkedList() {
        top = nullptr;
    }

    // Push operation: Adds element to the top of the stack
    void push(int x) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap Overflow\n";
            return;
        }
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed to stack\n";
    }

    // Pop operation: Removes the top element
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack\n";
        delete temp;
    }

    // Peek operation: Returns the top element without removing it
    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    StackLinkedList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element is " << stack.peek() << endl;
    stack.pop();
    cout << "Top element is " << stack.peek() << endl;
    return 0;
}
