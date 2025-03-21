/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-08-09.  
           
  TIME: 2:01 AM.
*/


#include <iostream>
using namespace std;

int main() {
    int a = 334;
    int *p = &a;

    cout << "p ka address: " << p << "\np ki value: " << *p ;

    (*p)++;

    cout << "\n++p ka address: " << ++p << "\n++p ki value: " << (*p) ;


    return 0;
}


