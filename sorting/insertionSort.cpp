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
void printArray( int arr[], int size,char name []) {
    cout << name <<"{";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if(i!=size-1){
            cout << ",";
        }
    }

    cout << "}" <<  endl;
}
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
       // printArray(arr,size,"pass:");
        int current = arr[i];
        int previous= i - 1;
        // Move elements of arr[0..i-1], that are greater than key with their next value
        while (previous>= 0 && arr[previous] > current) {
            arr[previous+ 1] = arr[previous];
            previous--;
        }
        arr[previous+ 1] = current;
    }
}
void insertion1Sort(int arr[], int size){
    for (int i = 1; i < size; ++i) {
        int holePosition =i-1;
        int toInsert = arr[i];
        while (holePosition>=0 && arr[holePosition]>toInsert){
            arr[holePosition+1]=arr[holePosition];
            holePosition--;
        }
        arr[++holePosition]=toInsert;
    }
}
int main() {
    int array[] = {1,10,2,9,3,8,4,7,5,6};
    int siz = sizeof(array) / sizeof(array[0]);
    printArray(array, siz,"Before sorting");
    insertion1Sort(array, siz);

    printArray(array, siz,"After sorting");
    return 0;
}
