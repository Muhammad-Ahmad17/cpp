/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-02.  
           
  TIME: 11:01 PM.
*//*
*//**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-07-02.

  TIME: 10:57 PM.
*//*
*//**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-07-02.

  TIME: 10:30 PM.
*//*
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

void Init(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i]=i;
    }
}

int main() {

    int size = 10;
    int prime[size];  // Declare array here

    Init(prime, size);  // Pass array name and size to fillArray
    printArray(prime, size); // Print filled array

    return 0;

}*/

#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to initialize the array with the first 'size' prime numbers
void Init(int arr[], int size) {
    int count = 0;
    int num = 2;  // Starting from the first prime number

    while (count < size) {
        if (isPrime(num)) {
            arr[count] = num;
            count++;
        }
        num++;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    int size = 10;
    int primes[size];  // Declare array here

    Init(primes, size);  // Pass array name and size to Init
    printArray(primes, size); // Print filled array

    return 0;
}
