
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to maintain MinHeap property after insertion
void heapifyUpMin(vector<int>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Function to insert value into MinHeap
void insertMinHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUpMin(heap, heap.size() - 1);
}

// Function to display the heap
void displayHeap(const vector<int>& heap) {
    if (heap.empty()) {
        cout << "Heap is empty.\n";
        return;
    }
    for (int value : heap) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> minHeap;
    int choice;

    do {
        cout << "\n--- MinHeap Menu ---\n";
        cout << "1. Insert into MinHeap\n";
        cout << "2. Display MinHeap\n";
        cout << "-1. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (minHeap.size() >= 10) {
                cout << "Heap is full (10 elements max).\n";
                continue;
            }
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            insertMinHeap(minHeap, value);
        } else if (choice == 2) {
            displayHeap(minHeap);
        } else if (choice != -1) {
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != -1);

    return 0;
}
