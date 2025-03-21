#include <iostream>
using namespace std;

void shape (int height,char symbol = '*'){
    for (int ln=1 ; ln<=height ; ln++){
        for(int smbl=1 ; smbl<=ln ; smbl++){
            cout << symbol;
        }
        cout << "\n";
    }
}
int main() {
    shape(5);

    return 0;
}