#include <iostream>
using namespace std;

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    // Copy any remaining elements
    for (;i<leftSize;){
        arr[k++] = leftArr[i++];
    }
    for (;j<rightSize;) {
        arr[k++] = rightArr[j++];
    }
    // Free the dynamically allocated memory
    delete[] leftArr;
    delete[] rightArr;
}
void mergre(int arr[], int left, int mid, int right) {

    int leftSize = mid-left+1;
    int rightSize = right-mid;

    int* leftArr = new int [leftSize];
    int * rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i=0,j=0,k=left;

    while (i<leftSize && j<rightSize){
        if(leftArr[i]<=rightArr[j]){
            arr[k++]=leftArr[i++];
        }else {
            arr[k++]=rightArr[j++];
        }
    }
    for (;i<leftSize;){
        arr[k++] = leftArr[i++];
    }
    for (;j<rightSize;) {
        arr[k++] = rightArr[j++];
    }

    delete [] leftArr;
    delete [] rightArr;
}
// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // for doing single element
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        //merge(arr, left, mid, right);
        mergre(arr, left, mid, right);
    }
}
void merge1Sort(int arr[], int left, int right) {
    if ( left<right) {
        int mid = left + (right - left) / 2;
        merge1Sort(arr, left, mid );
        merge1Sort(arr, mid+1, right);
        mergre(arr, left, mid, right);
    }
}
// Main function to test Merge Sort
int main() {
    int arr[] = {1,9,2,8,3,7,4,6,5,3};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using Merge Sort
    merge1Sort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
