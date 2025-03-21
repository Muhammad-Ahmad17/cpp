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
    int *ptr = new int (4);

    cout << *ptr << "\n" ;
    cout << sizeof(int) ;

    delete ptr;
    return 0;
}
