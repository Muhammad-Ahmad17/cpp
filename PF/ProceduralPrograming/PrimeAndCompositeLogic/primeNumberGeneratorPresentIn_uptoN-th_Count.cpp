/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.           *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/

#include <cmath>
#include <iostream>

using namespace std;

bool isPrimeNumber(int num);



int main() {
    int range;
    cout << "Enter the number of prime numbers to generate: ";
    cin >> range;

    int number=1;
    int count = 0;
    for (int i=1 ; i<range ; i++){
        if (isPrimeNumber(number)){
            cout << number << "";
            count++
        }
        number++;
    }

    return 0;
}

bool isPrimeNumber(int num) {
    if (num <= 1)
        return false; // 0 and 1 are not prime numbers
    if (num == 2)
        return true;  // 2 is the only even prime number
    if (num % 2 == 0)
        return false; // Other even numbers are not prime

    // Only check odd numbers up to the square root of num
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0)
            return false;
    }
    return true; // If no divisors found, num is prime
}
