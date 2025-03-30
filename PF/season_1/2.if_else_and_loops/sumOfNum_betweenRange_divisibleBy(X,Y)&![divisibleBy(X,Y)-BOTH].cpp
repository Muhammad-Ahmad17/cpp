/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.          *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/
#include <iostream>
using namespace std;


int main() {
    int rangeInitial,rangeFinal;    // 1-100
    int iSDivisibleBy_X , iSDivisibleBy_Y;    // 3,5

    cout << "Enter range of numbers (separate by space)"; cin >> rangeInitial >> rangeFinal;
    cout << "Enter the numbers which are to be divisible:"; cin >> iSDivisibleBy_X >>iSDivisibleBy_Y;

    for (int i=rangeInitial ; i<=rangeFinal ; i++){
        if ((i%iSDivisibleBy_X == 0 || i %iSDivisibleBy_Y == 0)){
            if (!(i%iSDivisibleBy_X == 0 && i %iSDivisibleBy_Y == 0)) {
                cout << i << " ";
            }
        }
    }

    return 0;
}