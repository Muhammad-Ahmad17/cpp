/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-08-09.  
           
  TIME: 1:22 AM.
*/
#include <iostream>
using namespace std;


int main() {
    int a=5;
    int *ptr = &a;

    int b=5.8;
    int *p = &b;



    cout << "size of ptr of int: " << sizeof (ptr);
    cout << "\nsize of ptr of double: " << sizeof (p);
    return 0;
}
