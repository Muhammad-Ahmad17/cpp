/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-16.  
           
  TIME: 10:23 PM.
*/
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int arr[6]={2,4,6,3,23,43};
    int *p=arr ;
    for (int i=0 ; i<=5 ; i++){
        cout << endl << i << "-th element: " << * (arr+i);
    }
    delete p;

    return 0;
}
