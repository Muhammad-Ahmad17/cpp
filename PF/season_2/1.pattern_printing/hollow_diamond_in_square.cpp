/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-06-28.

  TIME: 7:02 PM.
*/

#include <iostream>
using namespace std;

void ultaPajama (int height,int startingLine=1,char space = ' ',char symbol_1 = '*',char symbol_2 = '*'){
    for (int ln=startingLine ; ln<=height ; ln++){
        for(int smbl_1=1 ; smbl_1 <= ln ; smbl_1++){
            cout << symbol_1;
        }
        for (int spc=1 ; spc<=2*(height-ln) ; spc++){
            cout << space;
        }
        for(int smbl_2=1 ; smbl_2 <= ln ; smbl_2++){
            cout << symbol_2;
        }
        cout << "\n";
    }
}

void sidhaPajama (int height, char space = ' ', char symbol_1 = '*', char symbol_2 = '*'){
    for (int ln=1 ; ln<=height ; ln++){
        for(int smbl_1=1 ; smbl_1 <= (height+1)-ln ; smbl_1++){
            cout << symbol_1;
        }
        for (int spc=1 ; spc<=2*(ln-1) ; spc++){
            cout << space;
        }
        for(int smbl_2=1 ; smbl_2 <= (height+1)-ln ; smbl_2++){
            cout << symbol_2;
        }
        cout << "\n";
    }
}

int main() {
    sidhaPajama(5);
    ultaPajama(5,2);
}