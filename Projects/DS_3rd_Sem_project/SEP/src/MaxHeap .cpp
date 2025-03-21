
#include "MaxHeap .h"

using namespace std ;

    void MaxHeap::push(double value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    double MaxHeap::pop() {
        if (heap.empty()) throw out_of_range("Heap is empty.");
        double topValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return topValue;
    }

    double MaxHeap::top() const {
        if (heap.empty()) throw out_of_range("Heap is empty.");
        return heap[0];
    }

    bool MaxHeap::empty() const {
        return heap.empty();
    }

    void MaxHeap::heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void MaxHeap::heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

