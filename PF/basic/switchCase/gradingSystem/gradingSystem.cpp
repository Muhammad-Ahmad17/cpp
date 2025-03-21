#include <iostream>
using namespace std;

int main() {
    int score;
    cout << " enter your score: ";  cin >> score ;

    switch (score){
        case 85 ... 100 :
            cout << "A+_grade"; break;
        case 80 ... 84 :
            cout << "A_grade"; break;
        case 75 ... 79 :
            cout << "B_grade"; break;
        case 70 ... 74 :
            cout << "C_grade"; break;
        case 65 ... 69 :
            cout << "D_grade"; break;
        case 60 ... 64 :
            cout << "E_grade"; break;
        case 55 ... 59 :
            cout << "F_grade"; break;
        default:
            cout << "AH'HH";
    }
    return 0;
}
