/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-08-08.  
           
  TIME: 11:51 PM.
*/
#include <iostream>
using namespace std;

// size of any type of pointer is 8
// because it stores address only

int main() {

            /*Basic Creation Of Pointers*/

   /* // method 1
    int a = 5;
    int *p = &a;*/

     /*// method 2
    int *p = new int{5}; // (5) same*/

    /* // method 3
     int a = 5;
     int *p = 0;
     p = &a ;*/


    cout << "*p ki value :" << *p;
    cout << "\np ki value :" << p;

    return 0;
}
