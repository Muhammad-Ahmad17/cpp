#include <iostream>
#include <stdexcept> // For std::out_of_range

class Vector {
private:
    int* arr;
    int currentSize;
    int currentCapacity;

    void resize() {
        int newCapacity = currentCapacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < currentSize; ++i) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        currentCapacity = newCapacity;
    }

public:
    Vector(int initialCapacity = 10)
        : currentSize(0), currentCapacity(initialCapacity) {
        arr = new int[currentCapacity];
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(int value) {
        if (currentSize == currentCapacity) {
            resize();
        }
        arr[currentSize++] = value;
    }

    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    int size() const {
        return currentSize;
    }

    int capacity() const {
        return currentCapacity;
    }

    int at(int index) const {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    int& operator[](int index) {
        return arr[index];
    }

    void insert(int index, int value) {
        if (index < 0 || index > currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        if (currentSize == currentCapacity) {
            resize();
        }
        for (int i = currentSize; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        ++currentSize;
    }

    void erase(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < currentSize - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --currentSize;
    }

    bool empty() const {
        return currentSize == 0;
    }

    void clear() {
        currentSize = 0;
    }
};

int main() {
    Vector vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    
    std::cout << "Elements: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.insert(1, 15);
    std::cout << "After inserting 15 at index 1: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.pop_back();
    std::cout << "After pop_back: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
