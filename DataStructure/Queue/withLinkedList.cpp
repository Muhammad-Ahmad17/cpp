#include <iostream>
using namespace std;

// A class to represent a node of the linked list
class Node {
public:
    int data;
    Node* next;
};

// Queue using linked list
class QueueLinkedList {
private:
    Node* front; // Pointer to the front element
    Node* rear;  // Pointer to the rear element

public:
    // Constructor to initialize queue
    QueueLinkedList() {
        front = rear = nullptr;
    }

    // Enqueue operation: Adds an element to the rear
    void enqueue(int x) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap Overflow\n";
            return;
        }
        newNode->data = x;
        newNode->next = nullptr;

        if (rear == nullptr) { // If queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " enqueued to queue\n";
    }

    // Dequeue operation: Removes the front element
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) { // If the queue becomes empty
            rear = nullptr;
        }

        cout << temp->data << " dequeued from queue\n";
        delete temp;
    }

    // Peek operation: Returns the front element without removing it
    int peek() {
        if (front == nullptr) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    QueueLinkedList queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element is " << queue.peek() << endl;

    queue.dequeue();
    cout << "Front element is " << queue.peek() << endl;

    return 0;
}
