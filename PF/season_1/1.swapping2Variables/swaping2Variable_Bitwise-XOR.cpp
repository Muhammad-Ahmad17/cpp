#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "a = " << a << ", b = " << b << endl;  // a = 10, b = 5
    return 0;
}

//fastest of all


