/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-06-28.

  TIME: 6:34 PM.
*/

#include <iostream>
using namespace std;

void upwardPart (int height, char space = ' ', char symbol = '*'){
    for (int ln=1 ; ln<=height ; ln++){
        for (int spc=1 ; spc<=height-ln ; spc++){
            cout << space;
        }
        for(int smbl=1 ; smbl<=ln ; smbl++){
            cout << (smbl);
        }
        for (int smbl_2=1 , dig =ln; smbl_2<=ln-1 ; smbl_2++){
            cout <<--dig;

        }
        cout << "\n";
    }
}

int main() {
    upwardPart(10);
}