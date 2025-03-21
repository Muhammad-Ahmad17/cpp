/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-06-28.  
           
  TIME: 6:18 PM.
*/
#include <iostream>
using namespace std;

void upwardPart (int height, char space = ' ', char symbol = '*'){
    for (int ln=1 ; ln<=height ; ln++){
        for (int spc=1 ; spc<=ln-1 ; spc++){
            cout << space;
        }
        for(int smbl=1 ; smbl<=((height+1)-ln) ; smbl++){
            cout << symbol;
        }
        cout << "\n";
    }
}
int main() {
    upwardPart(5);
}