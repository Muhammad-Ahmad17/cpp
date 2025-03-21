/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-05.  
           
  TIME: 7:09 PM.
*/
#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target) {

    int low = 0, high = n - 1;

    while (low <= high ) {
        cout << "x\n";
        // Estimate the position
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Check if target is found
        if (arr[pos] == target)
            return pos;

        // If target is less than the value at pos, search in the left sub-array
        if (arr[pos] > target)
            high = pos - 1;
            // If target is greater than the value at pos, search in the right sub-array
        else
            low = pos + 1;
    }

    // Target not found
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 500, 600, 603, 690, 899, 8100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 899;

    int result = interpolationSearch(arr, n, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
