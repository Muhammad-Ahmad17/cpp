/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-05.  
           
  TIME: 8:49 PM.
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

void bubbleSorting(int arr[], int size) {
    bool swapped;
    do {
        swapped = false; //jab tak swap ho ga bubble up hota rahy ga kuch cases me 3 4 itration k bad hi array sort ho jati ha to unnecessary iteration say bachny k liay swap check lagaya ha
        for (int i = 0; i+1 < size; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        size--; // reduce the range after each pass
    } while (swapped);
}
int main() {
    int array[] = {1, 2, 3, 4, 500, 600, 603, 690, 899, 8100};
    int siz = sizeof(array) / sizeof(array[0]);
    printArray(array, siz,"Before sorting");
    bubbleSorting(array, siz);

    printArray(array, siz,"After sorting");
    return 0;
}
