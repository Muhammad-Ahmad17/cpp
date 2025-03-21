/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-18.  
           
  TIME: 4:41 PM.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}
// Function to partition the array around the pivot
int partition(int arr[], int lb, int up) {
    int& pivot = arr[up]; // Choosing the last element as the pivot
    int partitionIndex = lb - 1; // Tracks the position for elements <= pivot

    for (int i = lb; i < up; i++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[i] <= pivot) {
            //partitionIndex++;  // Increment the partition index
            swap(arr[++partitionIndex], arr[i]);  // Swap elements
        }
    }
    // Place the pivot in its correct position
    swap(arr[++partitionIndex ], pivot);
    return partitionIndex;  // Return the final pivot position
}
// Main function to test the Quick Sort algorithm
int main() {
    int arr[] = {1,9,2,8,3,7,5,7,4,6,5};  // Input array
    int arraySize = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array

    // Print the original array
    cout << "Given array: ";
    for (int index = 0; index < arraySize; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;

    // Perform Quick Sort on the array
    cout << "partition index :" << partition(arr, 0, arraySize - 1) << endl;

    // Print the sorted array
    cout << "parted array: ";
    for (int index = 0; index < arraySize; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}
