#include <iostream>
using namespace std;

int main() {
    char a = 5;
    char b = -33;

    cout << "Before swapping:\na:" << a << " , b:" << b;

    a=a+b; // 2+3 >5
    b=a-b; // 5-3 >2
    a=a-b; // 5-2 >3

    cout << "\nAfter swapping:\na:" << a << " , b:" << b;

    return 0;
}

