#include <iostream>
using namespace std;


int main() {

    for (int ln=1 ; ln<11 ;ln++){
        int minus=2;
        if (ln<6) {
            for (int spc = 1; spc <= ln - 1; spc++) {
                cout << " ";
            }
        } else {
            for (int spc = 1 ; spc <= ln - minus; spc++ ) {
                cout << " ";
                minus=minus+2;
            }
        }
        for (int str=1 ;str<=1 ;str++){
            cout << "*";
        }
        cout << endl;

    }
    return 0;
}
