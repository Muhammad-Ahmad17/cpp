/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-05.  
           
  TIME: 9:07 PM.
*/
#include <iostream>
using namespace std;

// 9 2 8 4 8 9 test this
void readArray( int arr[], int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void printArray( int arr[], int size,char* name) {
    cout << name <<"{";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if(i!=size-1){
            cout << ",";
        }
    }

    cout << "}" <<  endl;
}
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        // Find the minimum element in unsorted array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int array[] = {9,2,8,4,8,9};
    int siz = sizeof(array) / sizeof(array[0]);
    printArray(array, siz,"Before sorting");
    selectionSort(array, siz);

    printArray(array, siz,"After sorting");
    return 0;
}
