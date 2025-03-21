/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-02.  
           
  TIME: 10:57 PM.
*/
/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-02.  
           
  TIME: 10:30 PM.
*/
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

void Init(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i]=i;
    }
}

int main() {

    int size = 10;
    int whole[size];  // Declare array here

    Init(whole, size);  // Pass array name and size to fillArray
    printArray(whole, size); // Print filled array

    return 0;

}
