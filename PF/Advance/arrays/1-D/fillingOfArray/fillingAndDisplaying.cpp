/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-10.  
           
  TIME: 10:07 PM.
*/

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
void print_array (int arr[],int len , char name[]){
    cout << name << ": {";
    for (int i=0 ; i<=len-1 ; i++){
        cout  << arr[i] ;
        if (i==len-1) {} else cout << "," ;
    }
    cout << "}";
}
int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];
    readArray( arr, size);

    print_array( arr, size, "lopoooo");

    return 0;
}
