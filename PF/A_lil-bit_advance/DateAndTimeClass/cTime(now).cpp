/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-06-28.  
           
  TIME: 12:42 AM.
*/
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t now = std::time(0);
    cout << "Current time: " << ctime(&now);
    return 0;
}