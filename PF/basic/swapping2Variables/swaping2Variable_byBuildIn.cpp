//
// Created by AR Computers on 6/20/2024.
//
#include "algorithm" // Required for std::swap
#include "iostream"
using namespace std;

int main() {
    int a = 5, b = 10;

    cout << "Before swapping:\n";
    cout << "a = " << a << ", b = " << b << endl;  // a = 5, b = 10

    swap(a, b);

    cout << "After swapping:\n";
    cout << "a = " << a << ", b = " << b << endl;  // a = 10, b = 5

    return 0;
}