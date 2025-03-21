/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-16.  
           
  TIME: 10:36 PM.
*/
#include <iostream>
using namespace std;

int factorial (int n){
    if (n==1){
        return 1;
    }
    return n * factorial(n-1);
}
int main() {
    cout << factorial(5);

    return 0;
}
