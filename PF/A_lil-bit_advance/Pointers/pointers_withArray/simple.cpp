/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-08-11.  
           
  TIME: 7:51 PM.
*/
#include <iostream>
using namespace std;


int main3() {

    int arr[] = {1,4,5,2,7,6,8,74,5};
    int *ptr=arr;
    cout << ptr <<" "<<*ptr<<endl;
    ptr = ptr+1;
    cout << ptr <<" "<<++*ptr;
    cout << endl;

    cout << ptr[*arr+2];
    cout << endl;
    cout << arr[*ptr];

    return 0;
}
int main(){
    int arr[5] = {5, 10, 15, 20, 25};
    int *ptr = arr;
    cout <<endl;
    cout << *ptr;

    cout <<endl;
    cout << *(ptr + 2);

    cout <<endl;
    cout << *(arr + 4);

    cout <<endl;
    cout << ptr[3];

    cout <<endl;
    return 0;
}
