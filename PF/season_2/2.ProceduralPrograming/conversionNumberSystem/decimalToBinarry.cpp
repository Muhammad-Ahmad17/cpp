/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.           *
 *                             *
 * Date: 2024-06-27.           *
 *******************************/
#include <iostream>
using namespace std;

void decimalToBinary(int decimalNumber, int binary[], int& size) {
    int i = 0;
    while (decimalNumber > 0) {
        binary[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }
    size = i; // Set the size to the number of binary digits
}

void printArray(int arr[], int size) {
    for (int i = size - 1; i >= 0; --i) { // Print in reverse order to get the correct binary representation
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int binary[32]; // Assuming a maximum of 32 bits for the binary representation
    int size = 0; // Size of the binary array

    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    decimalToBinary(decimalNumber, binary, size);

    cout << "Binary representation: ";
    printArray(binary, size);

    return 0;
}
