/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-20.  
           
  TIME: 6:05 AM.
*/
#include <iostream>
using namespace std;

int binarySearch(const int arr[], int target, int left, int right) {

    if (left > right) { // Base case: target not found
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
     else if (arr[mid] > target)
        return binarySearch(arr, target, left, mid - 1);
     else
        return binarySearch(arr, target, mid + 1, right);
}
//_________________________________________________________________
int main() {
    int a[5] = {1, 3, 5, 4, 8};
    int len = 5;
    int result = binarySearch(a, 98, 0, len - 1);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
