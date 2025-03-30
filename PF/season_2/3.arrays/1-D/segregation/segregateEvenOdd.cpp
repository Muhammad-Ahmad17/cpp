#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

void segregateEvenOdd(int* arr, int size) {
    int* left = arr;               
    int* right = arr + size - 1;   
    
        while (left < right) {

        // Move the left pointer forward if it points to an even number
        while (*left % 2 == 0) {
            left++;
        }
        // Move the right pointer backward if it points to an odd number
        while (*right % 2 != 0) {
            right--;
        }
        // Swap the values at the left and right pointers
        if (left < right) {
            swap(*left, *right);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {12, 17, 70, 15, 22, 65, 21, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    segregateEvenOdd(arr, size);

    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}