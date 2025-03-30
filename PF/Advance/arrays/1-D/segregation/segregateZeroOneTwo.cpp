#include <iostream>
using namespace std;

// Function to segregate 0s, 1s, and 2s
void segregateZeroOneTwo(int* arr, int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap arr[low] and arr[mid], increment low and mid
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            // Move mid pointer forward
            mid++;
        } else { // arr[mid] == 2
            // Swap arr[mid] and arr[high], decrement high
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[] = {1,1,1,1,1,1,1,1};
    int arr3[] = {2, 0, 2, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    segregateZeroOneTwo(arr, size);

    cout << "Array after segregation: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*Dutch National Flag Algorithm:

Purpose: It is used to segregate or sort elements into three groups (e.g., 0s, 1s, and 2s) in a single traversal.
Approach: It uses three pointers (low, mid, and high) to partition the array into three regions:
Elements less than the pivot (0s).
Elements equal to the pivot (1s).
Elements greater than the pivot (2s).
Condition: It works on unsorted arrays and rearranges them in (O(n)) time.*/
