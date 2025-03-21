/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-24.  
           
  TIME: 3:32 AM.
*/
#include <iostream>
using namespace std;
//______________________________________________________
void print_array (int arr[],int len ,const char* name){
    cout << name << ":{";
    for (int i=0 ; i<=len-1 ; i++){
        cout  << arr[i] ;
        if (i==len-1) {} else cout << "," ;
    }
    cout << "}";
}
//______________________________________________________
void swap(int *a ,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//______________________________________________________
void shiftZeroAtEnd(int arr[],int len) {
    int *ptr1 = arr;
    int *ptr2 = (arr + (len - 1));

    while (ptr1<ptr2) {
        if (*ptr1 == 0) {
            while (ptr2 > ptr1) {
                if (*ptr2 != 0) {
                    swap(ptr1, ptr2);
                    ptr2--;
                    break;
                } else {
                    ptr2--;
                }
            }
        } else {
            ptr1++;
        }
    }
}
//______________________________________________________

int main() {
    int array[5] = {1,0,1,0,1};
    int length = sizeof(array) / sizeof(array[0]);
    print_array(array,length,"before shifting");
    cout << endl;
    shiftZeroAtEnd(array,length);
    print_array(array,length,"after shifting");
    return 0;
}
