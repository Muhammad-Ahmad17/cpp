/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.           *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/

#include <iostream>
#include <cmath> // Include cmath for sqrt() and floor()
using namespace std;

bool isPerfectSquare(int num) {
    if (num < 0) return false; // Negative numbers cannot be perfect squares
    int root = static_cast<int>(sqrt(num));
    return root * root == num;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }

    return 0;
}
