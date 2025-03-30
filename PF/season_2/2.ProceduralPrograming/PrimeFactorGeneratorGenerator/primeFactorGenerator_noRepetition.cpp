/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.          *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/
/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.           *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/

#include <iostream>
#include <cmath>
using namespace std;

void isPrimeFactor(int num);

int main() {
    isPrimeFactor(60);
    return 0;
}

void isPrimeFactor(int num) {
    // Check for the number of 2s that divide num
    bool printed = false;
    while (num % 2 == 0) {
        if (!printed) {
            cout << 2 << " ";
            printed = true;
        }
        num /= 2;
    }

    // num must be odd at this point, thus skip even numbers
    for (int i = 3; i <= sqrt(num); i += 2) {
        printed = false;
        // While i divides num, print i and divide num
        while (num % i == 0) {
            if (!printed) {
                cout << i << " ";
                printed = true;
            }
            num /= i;
        }
    }

    // This condition is to handle the case when num is a prime number
    // greater than 2
    if (num > 2)
        cout << num << " ";
}
