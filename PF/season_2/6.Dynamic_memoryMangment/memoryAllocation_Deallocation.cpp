/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-05.  
           
  TIME: 8:02 PM.
*/
#include <iostream>
using namespace std;


int main() {
    int *ptr = new int (4); // allocate

    cout << *ptr << "\n" ; //use
    cout << sizeof(int) ; //print

    delete ptr; // deallocate
    return 0;
}
