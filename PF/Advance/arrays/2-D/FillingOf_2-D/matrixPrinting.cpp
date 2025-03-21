#include <iostream>
const int SIZE = 3;
using namespace std;

void fillMatrix(int arr[][SIZE], int i, int j) {
    for (int i_R = 0; i_R < i; i_R++) {
        for (int j_R = 0; j_R < j; j_R++) {
            cout << "Enter element at position (" << i_R << ", " << j_R << "): ";
            cin >> arr[i_R][j_R];
        }
    }
}

void displayMatrix(int arr[][SIZE], int i, int j) {
    cout << "The filled matrix is:" << endl;
    for (int i_R = 0; i_R < i; i_R++) {
        for (int j_R = 0; j_R < j; j_R++) {
            cout << arr[i_R][j_R] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[SIZE][SIZE];  // Define a matrix with the constant SIZE
    fillMatrix(arr, SIZE, SIZE);  // Call the function to fill the matrix
    displayMatrix(arr, SIZE, SIZE);  // Call the function to display the matrix
    return 0;
}
