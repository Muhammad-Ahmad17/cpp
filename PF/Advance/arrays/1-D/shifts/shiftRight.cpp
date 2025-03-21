/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-10.  
           
  TIME: 10:07 PM.
*//*

 // Shifting an array [1, 2, 3, 4, 5] right by one position results in
                      [5, 1, 2, 3, 4].


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


void shiftRight(int arr[] , int size ){
    for (int i=size-1 ; i+1<0 ; i--){
        swap(arr[i],arr[i+1]);
    }
}

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    readArray( arr, size);

    cout << "Display after shifting : ";
    shiftRight(arr, size);
    printArray( arr, size);

    return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

void readArray(int arr[], int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void printArray(int arr[], int size) {
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
    if (size <= 1) return;  // No need to shift if array size is 0 or 1

    // Reverse the entire array
    reverse(arr, arr + size);

    // Reverse the first size-1 elements
    reverse(arr, arr + size - 1);

    // Reverse the last element
    reverse(arr + size - 1, arr + size);
}

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
    shiftRight(arr, size);
    printArray(arr, size);

    return 0;
}
