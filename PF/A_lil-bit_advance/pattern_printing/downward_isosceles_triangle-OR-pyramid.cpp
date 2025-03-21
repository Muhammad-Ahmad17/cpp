/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-06-28.  
           
  TIME: 6:38 PM.
*/

#include <iostream>
using namespace std;

void downwardPart (int height,char space = ' ',char symbol = '*'){
    for (int ln=1 ; ln<=height ; ln++){
        for (int spc=1 ; spc<=ln-1 ; spc++){
            cout << space;
        }
        for(int smbl=1 ; smbl<=2*(height-ln)+1 ; smbl++){
            cout << symbol;
        }
        cout << "\n";
    }
}

int main() {
    downwardPart(5);
}