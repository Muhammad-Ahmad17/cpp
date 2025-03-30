/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.          *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/


#include <limits>
#include "iostream"
using namespace std;

int main() {
    int  number;
    int max = 0;
    int max_1 = 0;
    int min = numeric_limits<int>::max();  // Largest possible integer


    //cout << min;

    /*program is evaluating each number untill -1 */
    cout << "Enter numbers (separate by space) press -1 to end:";
    cin >> number; // initial number 

    while(number!=-1) {
        if (number>max) {
            max_1=max;
            max=number;
        }
        if (number<min) min=number;
        cin >> number; // repetition of number untill -1
    }

    cout << "Max:" << max << "\nMin:" << min << "\n2nd-Max:" << max_1;
    return 0;
}