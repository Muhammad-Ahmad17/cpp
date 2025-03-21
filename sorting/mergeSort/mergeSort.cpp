#include <iostream>
using namespace std;

// Function to merge two sorted halves into a single sorted array
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    // Compare elements from both halves and merge them in sorted order
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    // If there are remaining elements in the left half, add them to the array
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    // If there are remaining elements in the right half, add them to the array
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
    /*
    for(;i<l1;i++)
        c[k++]=a[i++];
    for(;j<l2;j++)
        c[k++]=b[j++];*/
}

// Function to partition the array into left and right halves
void partition(int arr[], int size, int*& left, int*& right, int& leftSize, int& rightSize) {
    // Find the middle point to split the array into two halves
    int mid = size / 2;

    leftSize = mid;
    rightSize = size - mid;

    // Allocate memory for left and right halves
    left = new int[leftSize];
    right = new int[rightSize];

    // Copy the left half of arr into left array
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[i];
    }

    // Copy the right half of arr into right array
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int size) {
    // Base case: If the array has 1 or no elements, it's already sorted
    if (size <= 1) {
        return;
    }

    int* left=nullptr;
    int* right=nullptr;
    int leftSize=0, rightSize=0;

    // Partition the array into left and right halves
    partition(arr, size, left, right, leftSize, rightSize);

    // Recursively sort the two halves
    mergeSort(left, leftSize);
    mergeSort(right, rightSize);

    // Merge the sorted halves back together
    merge(arr, left, leftSize, right, rightSize);

    // Free the dynamically allocated memory
    delete[] left;
    delete[] right;
}
// Main function to test Merge Sort
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using Merge Sort
    mergeSort(arr, arrSize);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
