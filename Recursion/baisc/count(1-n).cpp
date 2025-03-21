/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-28.  
           
  TIME: 5:45 PM.
*/
#include "iostream"
using namespace std;

int count (int n){

    if(n<=1) {
        return 1;
    }
    cout << n << " ";
    return count(n-1);

}
int main(){

    cout << count(8);
    return 0;
}
