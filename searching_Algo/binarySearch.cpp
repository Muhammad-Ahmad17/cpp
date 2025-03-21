/**
  Copyright (c) 2024

  Name: MUHAMMAD AHMAD.

  Project Name: PF.

  Date: 2024-09-23.

  TIME: 9:56 PM.
*/
#include <iostream>
using namespace std;

int binarySearch(const int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        cout << "x\n";
        int mid = low + (high - low) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int array[] = {1, 2, 3, 4, 500, 600, 603, 690, 899, 8100};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 690;
    int result = binarySearch(array, size, target);
    if (result != -1) {
        cout << "Element found at index: " << result ;
    } else {
        cout << "Element not found" ;
    }
    return 0;
}
