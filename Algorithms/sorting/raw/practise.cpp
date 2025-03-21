#include <iostream>
#include "algorithm"
using namespace std;

// 9 2 8 4 8 9 test this
void readArray( int arr[], int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

void printArray( int arr[], int size) {
    cout << "Array elements are: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
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
    int siz;
    cout << "Enter the size of the array : ";
    cin >> siz;

    int array[siz];
    readArray(array, siz);


    cout << "Before sorting : ";
    printArray(array, siz);
    bubbleSorting(array, siz);
    cout << "After sorting : ";
    printArray(array, siz);
    return 0;
}
