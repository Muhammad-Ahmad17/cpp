/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-12-10.  
           
  TIME: 12:20 AM.
*/
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to maintain MaxHeap property after insertion
void heapifyUpMax(vector<int>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Function to insert value into MaxHeap
void insertMaxHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUpMax(heap, heap.size() - 1);
}

// Function to maintain MaxHeap property after deletion
void heapifyDownMax(vector<int>& heap, int index) {
    int size = heap.size();
    while (index < size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

// Function to delete the maximum element
void deleteMax(vector<int>& heap) {
    if (heap.empty()) {
        cout << "Heap is empty, nothing to delete.\n";
        return;
    }
    cout << "Deleted: " << heap[0] << endl;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDownMax(heap, 0);
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
    vector<int> maxHeap;
    int choice;

    do {
        cout << "\n--- MaxHeap Menu ---\n";
        cout << "1. Insert into MaxHeap\n";
        cout << "2. Delete from MaxHeap\n";
        cout << "3. Display MaxHeap\n";
        cout << "-1. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            insertMaxHeap(maxHeap, value);
        } else if (choice == 2) {
            deleteMax(maxHeap);
        } else if (choice == 3) {
            displayHeap(maxHeap);
        } else if (choice != -1) {
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != -1);

    return 0;
}
