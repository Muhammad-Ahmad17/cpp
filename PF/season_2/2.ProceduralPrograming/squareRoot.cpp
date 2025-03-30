#include <iostream>
#include <cmath>

using namespace std;

/*void squareRoot(int n){
    int x;
    for (int i =2 ;  x!=0 ; i++){
        if ((i*i)==n){
            cout << i << " is the square root of " << n;
            x=0;
        }
    }
}*/
void squareRoot(int n){
    int x;
    for (float i =2.0 ;  x!=0 ; i=i+0.5){
        if (int(i*i)==n){
            cout << i << " is the square root of " << n;
            x=0;
        }
    }

}
int main() {

    squareRoot( 5);
    return 0;
}
/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-14.  
           
  TIME: 5:33 AM.
*/
