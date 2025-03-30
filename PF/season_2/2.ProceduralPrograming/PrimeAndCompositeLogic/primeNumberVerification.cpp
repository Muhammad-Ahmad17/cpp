/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.           *
 *                             *
 * Date: 2024-06-25.           *
 *******************************/
#include "cmath"
#include <iostream>
using namespace std;

bool isPrimeNumber(int num);

int main() {
    int num;
    cout << "Enter number to check prime:"; cin >> num;

    if (isPrimeNumber(num)) {
        cout<<"yeee..";
    } else {
        cout<<"nooo..";
    }
    return 0;
}

bool isPrimeNumber(int num) {
    if (num <= 2)
        return (num==2)? true:false;
   /* if (num <= 1)
        return false; // 0 and 1 are not prime numbers
    if (num == 2)
        return true;  // 2 is the only even prime number*/
    if (num % 2 == 0)
        return false; // Other even numbers are not prime

    // Only check odd numbers up to the square root of num
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0)
            return false;
    }
    return true; // If no divisors found, num is prime
}

/*hear i do step by step method to return for fast answer*/