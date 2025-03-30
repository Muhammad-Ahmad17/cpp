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
    isPrimeFactor(4);
    return 0;
}

void isPrimeFactor(int num) {
    // Print the number of 2s that divide num
    while (num % 2 == 0) {
        cout << 2 << " ";
        num /= 2;
    }

    // num must be odd at this point, thus skip even numbers
    for (int i = 3; i <= sqrt(num); i += 2) {
        // While i divides num, print i and divide num
        while (num % i == 0) {
            cout << i << " ";
            num /= i;
        }
    }

    // This condition is to handle the case when num is a prime number
    // greater than 2
    if (num > 2)
        cout << num << " ";
}
