/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-06.  
           
  TIME: 1:28 PM.
*/
#include <iostream>
#include "cmath"
using namespace std;

void print_array (int arr[],int len , char name[]){
    cout << name << ":{";
    for (int i=0 ; i<=len-1 ; i++){
        cout  << arr[i] ;
        if (i==len-1) {} else cout << "," ;
    }
    cout << "}";
}

int nearestElement(int marr[], int size, int target) {
    cout << "your target:" << target << endl;
    int minIndex = 0;
    int minDiff = abs(target - marr[0]);

    for (int i = 1; i < size; ++i) {
        int diff = abs(target - marr[i]);
        if (diff < minDiff) {
            minDiff = diff;
            minIndex = i; // Store the index of the nearest element
        }
    }
    return marr[minIndex]; // Return the nearest element
}

int main(){

    int array[] = {12,23,45,34,27};
    int length = sizeof(array) / sizeof(array[0]);
    print_array(array,length,"Given array");

    cout <<"\n"<<"Nearest element from your target is:" << nearestElement(array,length,25);


    return 0;
}