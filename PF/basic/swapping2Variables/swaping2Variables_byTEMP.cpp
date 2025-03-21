//
// Created by AR Computers on 6/20/2024.
//
#include <iostream>
using namespace std;

int main() {
    float a = 2.2;
    float b = 3;
    float T;

    cout << "Before swapping:\na:" << a << " , b" << b;

    T=a;
    a=b;
    b=T;

    cout << "\nAfter swapping:\na:" << a << " , b" << b;

    return 0;
}
