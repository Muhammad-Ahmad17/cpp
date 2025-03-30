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
    int  number;
    int evenCount = 0, oddCount = 0;

    cout << "Enter numbers (separate by space) press -1 to end:";
    cin >> number;

    while(number!=-1) {
           if (number % 2 == 0) evenCount++;
           else oddCount++;
        cin >> number;
   }
    cout << "Even count:" << evenCount << "\nOdd count:" << oddCount;
    return 0;
}