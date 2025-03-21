#include <iostream>
#include <cmath>
using namespace std;

int main1() {
    int getTotalDigits;
    int getNumber;
    int sum = 0;
    int T;

    cout << " Enter how many digits sum u want: " ;
    cin >> getTotalDigits;  // let dig. be 3

    cout << "Enter " << getTotalDigits << " digit number: ";
    cin >> getNumber; // 123

    T=getNumber; // for saving the original value

    // if for checking weather number is n_th digit
    if (getNumber <= (pow(10,getTotalDigits ) - 1) && getNumber >= (pow(10,getTotalDigits-1) - 1)) { // (123<=999) && (123>=111)
        // for loop for go threw all digs.
        for (int i = 1; i <= getTotalDigits; i++) {
            sum += getNumber % 10;
            getNumber /= 10;
        }
        getNumber=T; // for restoring the original value
        cout << "Sum of " << getNumber << " is: " << sum << ".";
    } else {
        cout << "Enter valid number ...";
    }
    return 0;
}
/*
problem 1:
1 9
2 99
3 999
4 9999
5 99999
sol 1:
 For ( n = 1 )   : ( 10^1 - 1 = 9 )
 For ( n = 2 )   : ( 10^2 - 1 = 99)
 For ( n = 3 )   : ( 10^3 - 1 = 999)

 1 1        10^(1-1) + 1 = 2
 2 11       10^(2-1) +1 = 11   (pow(10,getTotalDigit-1) -1
 3 111
 4 1111

*/
/*
problem 2:
 123 : 1 2 3
sol 2:
 123%10 = 3  ->  123/10 = 12
 12%10 = 2   ->  12/10 = 1
 1%10 = 1    ->  1/10 = 0
 */


int main() {

    int getTotalDigits;
    int getNumber;
    int sum = 0;
    int T = 0 ;

    cout << "Enter how many digits sum u want: " ;
    cin >> getTotalDigits;  // let dig. be 3

    cout << "Enter " << getTotalDigits << " digit number: ";
    cin >> getNumber; // 123

    while(false) {
        if (getNumber <= (pow(10,getTotalDigits ) - 1) && getNumber >= (pow(10,getTotalDigits-1) - 1)) {
            cout << "Enter " << getTotalDigits << " digit number: ";
            cin >> getNumber; // 123
            break;
        }
    }


    T=getNumber; // for saving the original value

    for (int i = 1; i <= getTotalDigits; i++) {
        sum += getNumber % 10;
        getNumber /= 10;
    }

    getNumber=T; // for restoring the original value
    cout << "Sum of " << getNumber << " is: " << sum << ".";

    return 0;
}