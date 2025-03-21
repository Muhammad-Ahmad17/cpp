/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-11.  
           
  TIME: 12:05 AM.
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

bool isBubbling(int arr[],int size){
    for (int i=0 ; i+1<size ; i++){
        if (arr[i]>arr[i+1])
        return true;
    }
    return false;
}
void bubbleUp(int arr[],int size){
    for (int i=0 ; i+1<size ; i++){
        if (arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
}

void bubbleSorting(int arr[],int size) {
    do {
        bubbleUp(arr,size);
    } while (isBubbling(arr, size));
}

int main() {
    //int siz;
    //cout << "Enter the size of the array : ";
    //cin >> siz;

    //int array[siz];
   // readArray(array, siz);

    int array[] = {1, 2, 3, 4, 500, 600, 603, 690, 899, 8100};
    int siz = sizeof(array) / sizeof(array[0]);
    printArray(array, siz,"Before sorting");
    bubbleSorting(array, siz);

    printArray(array, siz,"After sorting");
    return 0;
}
