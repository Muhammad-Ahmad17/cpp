#include <iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    // Creating a jagged array (each row has different column size)
    int** arr = new int*[row];

    int* colSizes = new int[row]; // Array to store column sizes

    // Taking input for different column sizes
    for (int i = 0; i < row; i++) {
        cout << "Enter number of columns for row " << i + 1 << ": ";
        cin >> colSizes[i];
        arr[i] = new int[colSizes[i]]; // Allocate memory for each row
    }

    // Taking input
    for (int i = 0; i < row; i++) {
        cout << "Enter " << colSizes[i] << " elements for row " << i + 1 << ": ";
        for (int j = 0; j < colSizes[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // Outputting the jagged array
    cout << "\nJagged Array:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing memory
    for (int i = 0; i < row; i++) {
        delete[] arr[i]; // Delete each row
    }
    delete[] arr;       // Delete row pointers
    delete[] colSizes;  // Delete column sizes array

    return 0;
}
