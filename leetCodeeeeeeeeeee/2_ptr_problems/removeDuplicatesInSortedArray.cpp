/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-02.  
           
  TIME: 8:27 PM.
*/
#include <iostream>
using namespace std;

//failed casaes {2,2,2} > {2} > {2,2}

//______________________________________________________
void print_array (int arr[],int len , char name[]){
    cout << name << ":{";
    for (int i=0 ; i<=len-1 ; i++){
        cout  << arr[i] ;
        if (i==len-1) {} else cout << "," ;
    }
    cout << "}";
}

//______________________________________________________
void removeDuplicate(int arr[], int& size) {
    int* p1 = arr;     // pointer to the current element
    int* p2 = arr + 1; // POINTER TO THE NEXT ELEMENT

    while (p2 < arr + size) {
        if (*p1 == *p2) {  // IF DUPLICATE IS FOUND
            // SHIFT ALL ELEMENTS TO THE LEFT BY ONE
            for (int i = (p2 - arr); i < size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            size--;  //SINCE DUPLICATE  REMOVES WE ALSO DECREASE THE SIZE OF THE ARRAY
        } else {
            p1++;
            p2++;
        }
    }
}
void removeDuplicates(int arr[] , int size ){
    int *ptr1 = arr;
    int *ptr2 = arr+1;
    int help1 = 0;
    int duplicateCount=0;

    for (int o=1;o<size;o++) {
        if (*ptr1 == *ptr2) {
            duplicateCount++;
            for (int i = 0; i < size - 1; i++) {
                arr[i+help1] = arr[i +help1+ 1];
            }
        } else {
            ptr1++;
            ptr2++;
            help1++;
        }
    }
//delete or shrink to size kar do vector lga k
    for (int i = size-duplicateCount; i <=size ; ++i) {
        arr[i]=00; //delete or shrink to size kar do vector lga k
    }
}
int main(){
    int array[] = {2,2,2};
    int length = sizeof(array) / sizeof(array[0]);
    print_array(array,length,"before removing");
    cout << endl;
    removeDuplicate(array,length);
    print_array(array,length,"after removing");
    return 0;
}