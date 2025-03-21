#include "MinHeap.h"

using namespace std;

    void MinHeap::push(double value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    double MinHeap::pop() {
        if (heap.empty()) throw out_of_range("Heap is empty.");
        double topValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return topValue;
    }

    double MinHeap::top() const {
        if (heap.empty()) throw out_of_range("Heap is empty.");
        return heap[0];
    }

    bool MinHeap::empty() const {
        return heap.empty();
    }

    void MinHeap::heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void MinHeap::heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }


