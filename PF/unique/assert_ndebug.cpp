/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-22.  
           
  TIME: 9:31 PM.
*/
#define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;

double inchesToCentimeters(double inches){
    assert(inches >= 0);
    return 2.54 * inches;
}
int main() {

    cout << inchesToCentimeters(-1) << endl;
    cout << inchesToCentimeters(1);

    return 0;
}
/*
 Summary:
> assert is a development tool to catch logic errors and bugs early.
> It terminates the program when the condition fails and provides debugging information.
> It’s meant to be used during development and debugging, not in production.
> Once the program is stable, you can disable assertions using the NDEBUG macro to
  prevent them from affecting production performance.
> In essence, assert helps to guarantee that the internal logic of your program behaves
  as expected during development, ensuring stability and correctness before you release
  the program to production.
 */