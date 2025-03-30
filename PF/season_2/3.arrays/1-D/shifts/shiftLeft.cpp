/*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
 =*                                                                          =*
 =*  Copyright (c) ${YEAR} ${AUTHOR}                                         =*
 =*  All rights reserved.                                                    =*
 =*                                                                          =*
 =*  This file is part of ${PROJECT_NAME}.                                   =*
 =*                                                                          =*
 =*  Date: ${DATE}                                                           =*
 =*                                                                          =*
 =*                                                                          =*
 =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=**/
// Shifting an array [1, 2, 3, 4, 5] left by one position results in
//                   [2, 3, 4, 5, 1].

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

//explain the function
// The function shiftLeft takes an array and its size as input and shifts 
// the elements of the array to the left by one position.
void shiftLeft(int arr[] , int size ){
    for (int i=0 ; i+1<size ; i++){
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
    shiftLeft(arr, size);
    printArray( arr, size);

    return 0;
}
