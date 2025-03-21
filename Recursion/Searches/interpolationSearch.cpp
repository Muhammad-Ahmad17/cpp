/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-23.  
           
  TIME: 10:21 PM.
*/
#include <iostream>

int interpolationSearch(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= array[low] && target <= array[high]) {
        if (low == high) {
            if (array[low] == target) return low;
            return -1;
        }

        int mid = low + ((target - array[low]) * (high - low)) / (array[high] - array[low]);

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
    int array[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 7;
     int result = interpolationSearch(array, size, target);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    return 0;
}