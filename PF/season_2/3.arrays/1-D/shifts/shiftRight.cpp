/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-10.  
           
  TIME: 10:07 PM.
*/


 // Shifting an array [1, 2, 3, 4, 5] right by one position results in
  //                    [5, 1, 2, 3, 4].


#include "algorithm"
#include <iostream>
using namespace std;

void readArray( int arr[], int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void printArray( int arr[], int size) {
    cout << "Array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shiftLeft(int arr[], int size) {
    for (int i = 0; i + 1 < size; i++) {
        swap(arr[i], arr[i + 1]);
    }
}

void shiftRight(int arr[], int size) {
    if (size <= 1) return;  // No shifting needed

    int last = arr[size - 1];  // Store last element
    for (int i = size - 1; i > 0; i--) {
        //arr[i] = arr[i - 1];  // Shift elements to the right
        swap(arr[i], arr[i - 1]);
    }
   // arr[0] = last;  // Move last element to the first position
}

// alternative approch
// uncomment the line 43 and 46 & comment the line 44

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    readArray(arr, size);

    // Left Shift
    cout << "Display after left shifting: ";
    shiftLeft(arr, size);
    printArray(arr, size);

    // Right Shift
    cout << "Display after right shifting: ";
    shiftRight(arr, size);// counter the above left shift to get the original array
    shiftRight(arr, size);// now shifting right
    printArray(arr, size);

    return 0;
}

// in case of shift by n positions call shift function n times