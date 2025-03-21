/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-20.  
           
  TIME: 4:45 PM.
*/
#include "iostream"
using namespace std;

void print(int arr[], int size, const char* name) {
    cout << name << ";{";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i + 1 < size) {
            cout << ",";
        }
    }
    cout << "}\n";
}

void merge(int arr[], int lb, int mid, int up) {
    int leftSize = mid - lb + 1;
    int rightSize = up - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // Copy elements to leftArr and rightArr
    for (int i = 0; i < leftSize; ++i) {
        leftArr[i] = arr[i + lb];
    }
    for (int j = 0; j < rightSize; ++j) {
        rightArr[j] = arr[j + mid + 1];
    }

    // Merge process
    int i = 0, j = 0, k = lb;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] >= rightArr[j]) {  // Use <= for stability
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy remaining elements
    while (i < leftSize) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightSize) {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int lb, int up) {
    if (lb < up) {
        int mid = lb + (up - lb) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, up);
        merge(arr, lb, mid, up);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 67, 8};  // Fixed array declaration
    int size = sizeof(array) / sizeof(array[0]);

    print(array, size, "before sort");
    mergeSort(array, 0, size - 1);
    print(array, size, "after sort");

    return 0;
}
