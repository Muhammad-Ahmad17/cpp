/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-10.  
           
  TIME: 11:49 AM.
*/
#include <iostream>
using namespace std;
int fibonacci(int n){

    if(n==0 )
        return 0;

    if(n==1 )
        return 1;

    return fibonacci(n-2) + fibonacci(n-1);

}

int main()
{
    cout<< fibonacci(2);
}