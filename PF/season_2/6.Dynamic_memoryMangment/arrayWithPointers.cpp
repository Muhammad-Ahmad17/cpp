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
        cout << endl << i << "-th element: " << * (arr+i) ; 
        cout << endl << i << "-th element: " << arr[i] ; // this is the same as above line
        cout << endl << i << "-th element: " << i[arr] ; // this is the same as above line 

        
        // low level implementationarr[i] is equivalent to *(arr+i) ===> arr points to the first(base) element's address i is the 
        // offset(1*4){4 bytes for int which may vary according to the archetecture of computer} from the base address 
        // ==> we know (a+b==b+a)
        // similarly (arr+i) is equivalent to (i+arr)
        // so we can say arr[i] == i[arr]
        // note : only posoble in cpp
    }
    delete p;

    return 0;
}
