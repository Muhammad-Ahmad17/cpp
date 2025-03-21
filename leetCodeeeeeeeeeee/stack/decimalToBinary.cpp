/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-11-06.  
           
  TIME: 8:48 PM.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
void dTb(int num){
    stack<int> stack;
    while(num!=0){
        stack.push(num % 2);
        num /= 2;
    }
    while(!stack.empty()){
        cout << stack.top();
        stack.pop();
    }

}
int main(){
    dTb(128);
    return 0;
}