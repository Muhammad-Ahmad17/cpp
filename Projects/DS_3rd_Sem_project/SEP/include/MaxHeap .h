
#ifndef SEP_MAXHEAP_H
#define SEP_MAXHEAP_H

#include <vector>
#include <stdexcept>

namespace std {

    class MaxHeap {
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

#endif // MAX_HEAP_H

