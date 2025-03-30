/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.          *
 *                             *
 * Date: 2024-06-28.           *
 *******************************/
#include <iostream>
#include <iomanip>

int main() {
using namespace std;
    int num = 42;
    double pi = 3.14159;

    // Default padding with spaces
    string str = "Hello";
    cout << "Default padding with spaces:\n";
    cout << setw(10) << num << "\n";
    cout << setw(10) << pi << "\n";
    cout << setw(10) << str << "\n";

    // Padding with a specific character
    cout << "\nPadding with '*':\n";
    cout << setfill('0') << setw(10) << num << "\n";
    cout << std::setfill('*') << setw(10) << pi << "\n";
    cout << setfill('*') << setw(10) << str << "\n";

    return 0;
}
