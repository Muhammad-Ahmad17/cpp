#include <iostream>
#include <algorithm> // For std::swap
using namespace std;

// Function to rearrange the array using pointers and std::swap
void segregateZeroOne(int* arr, int size) {
    int* left = arr;               // start
    int* right = arr + size - 1;   // end 

    while (left < right) { // mid

        // Move the left pointer forward if it points to 0
        while (*left == 0 ) {
            left++;
        }

        // Move the right pointer backward if it points to 1
        while (*right == 1 ) {
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
    int arr[] = {1,0,0,0, 0, 0, 0,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    segregateZeroOne(arr, size);

    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}