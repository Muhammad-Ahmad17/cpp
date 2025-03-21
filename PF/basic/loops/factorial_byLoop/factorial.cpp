//
// Created by AR Computers on 6/16/2024.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cerr << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }


    // Calculate factorial using a for loop
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Output the factorial
    cout << "Factorial of " << n << " is " << factorial << endl;

    return 0;
}
