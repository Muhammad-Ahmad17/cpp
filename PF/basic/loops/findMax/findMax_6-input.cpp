#include <iostream>
using namespace std;

int main() {
        int n, number, max_number, second_max_number;

        cout << "Enter the number of elements: ";
        cin >> n;

        if (n <= 0) {
            cout << "Number of elements should be greater than 0." << std::endl;
            return 1;
        }

        cout << "Enter number 1: ";
        cin >> max_number; // Initialize max_number with the first input

        for (int i = 1; i < n; ++i) {
            cout << "Enter number " << i + 1 << ": ";
            cin >> number;
            if (number > max_number) {
                second_max_number = max_number;
                max_number = number;
            }
        }

        cout << "The 1st-maximum number is: " << max_number << endl;
        cout << "The 2nd-maximum number is: " << second_max_number << endl;
        return 0;
}