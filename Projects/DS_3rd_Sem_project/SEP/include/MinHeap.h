
#ifndef SEP_MINHEAP_H
#define SEP_MINHEAP_H

#include <vector>
#include <stdexcept>

namespace std {

    class MinHeap {
    private:
        std::vector<double> heap;

        void heapifyDown(int index);
        void heapifyUp(int index);

    public:
        void push(double value);
        double pop();
        double top() const;
        bool empty() const;
    };

}

#endif // MIN_HEAP_H
