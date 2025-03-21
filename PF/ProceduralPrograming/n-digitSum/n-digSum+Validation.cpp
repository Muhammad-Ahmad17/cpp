#include "iostream"
#include "cmath"
using namespace std;

bool checkValidation(int range, int number);
int digitsSum(int range, int number);

int main() {
    int range;
    int number;

    cout << "Enter how many digits sum u want: ";
    cin >> range;  // let dig. be 3

    cout << "Enter " << range << " digit number: ";
    cin >> number; // 123

    digitsSum( range, number);

    return 0;
}

bool checkValidation(int range, int number) {
    int lowerBound = pow(10, range - 1); // Calculate the smallest number with 'range' digits
    int upperBound = pow(10, range) - 1; // Calculate the largest number with 'range' digits

    return (number > lowerBound && number < upperBound);
}

int digitsSum(int range, int number) {
    if (checkValidation(range, number)) {
        int T, sum = 0;
        T = number; // for saving the original value

        for (int i = 1; i <= range; i++) {
            sum += number % 10;
            number /= 10;
        }

        number = T; // for restoring the original value
        cout << "Sum of " << number << " is: " << sum << ".";

        return 0;
    } else {
        cerr << "na chawlain mar" ;
        return 1;
    }
}

