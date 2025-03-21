#include <iostream>
using namespace std;

// Function to print the array
void print(int arr[], int size, const char* name) {
    cout << name << ": {";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i + 1 < size) {
            cout << ", ";
        }
    }
    cout << "}\n";
}

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Shell Sort with simple swapping
void shellSort(int arr[], int size) {
    // Start with a large gap, then reduce the gap
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Perform a gapped sort for this gap size
        for (int i = gap; i < size; i++) {
            for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap) {
                swap(arr[j], arr[j - gap]); // Simple swap of elements
            }
        }
    }
}

int main() {
    int array[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int size = sizeof(array) / sizeof(array[0]);

    print(array, size, "Before sort");
    shellSort(array, size);
    print(array, size, "After sort");

    return 0;
}
