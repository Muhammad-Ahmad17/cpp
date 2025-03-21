/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-28.  
           
  TIME: 7:32 PM.
*/
#include <iostream>
using namespace std;

void printStars(int count) {
    if (count == 0) {
        return;
    }

    cout << "*";
    printStars(count - 1);
}

void printPattern(int n) {
    if (n == 0) {
        return;
    }
    printPattern(n - 1);

    printStars(n);

    cout << endl;
}

int main() {
    int n;

    // Call the recursive function to print the pattern
    printPattern(5);

    return 0;
}


void shape (int height,char symbol = '*'){
    for (int ln=1 ; ln<=height ; ln++){
        for(int smbl=1 ; smbl<=ln ; smbl++){
            cout << symbol;
        }
        cout << "\n";
    }
}
int main1() {
    shape(5);

    return 0;
}