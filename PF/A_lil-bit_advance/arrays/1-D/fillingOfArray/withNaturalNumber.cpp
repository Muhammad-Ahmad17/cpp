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
            arr[i]=i+1;
    }
}

int main() {

    int size=10;
    int natural[size];  // Declare array here

    cout << ">>"<< sizeof(natural)/4 << "<<";
    Init(natural, size);  // Pass array name and size to fillArray
    printArray(natural, size); // Print filled array

    return 0;
}
