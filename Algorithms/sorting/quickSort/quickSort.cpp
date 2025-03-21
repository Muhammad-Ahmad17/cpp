#include <iostream>
using namespace std;

// Function to partition the array around the pivot
int partition(int arr[], int lb, int up) {
    int& pivot = arr[up];  // Choosing the last element as the pivot
    int partitionIndex = lb - 1;  // Tracks the position for elements <= pivot

    for (int i = lb; i < up; i++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[i] >= pivot) {
            swap(arr[++partitionIndex], arr[i]);  // Swap elements
        }
    }
    // Place the pivot in its correct position
    swap(arr[++partitionIndex], pivot);
    return partitionIndex;  // Return the final pivot position
}
// Function to perform Quick Sort
void quickSort(int arr[], int lb, int up) {
    if (lb < up) {
        int pivotIndex = partition(arr, lb, up);  // Get the partition index
        quickSort(arr, lb, pivotIndex - 1);  // Recursively sort elements before partition
        quickSort(arr, pivotIndex + 1, up);  // Recursively sort elements after partition
    }
}
// Main function to test the Quick Sort algorithm
int main() {
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};  // Input array
    int arraySize = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array

    // Print the original array
    cout << "Given array: ";
    for (int index = 0; index < arraySize; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;

    // Perform Quick Sort on the array
    quickSort(arr, 0, arraySize - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int index = 0; index < arraySize; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}
