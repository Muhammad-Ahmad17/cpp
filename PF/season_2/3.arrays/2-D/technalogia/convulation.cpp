#include <iostream>

using namespace std;

// Function to perform 2D convolution
void convolve2D(int input[5][5], int kernel[3][3], int output[3][3]) {
    int inputRows = 5;
    int inputCols = 5;
    int kernelRows = 3;
    int kernelCols = 3;
    
    // Perform convolution
    for (int i = 0; i <= inputRows - kernelRows; ++i) {
        for (int j = 0; j <= inputCols - kernelCols; ++j) {
            int sum = 0;
            // Apply kernel to the region
            for (int m = 0; m < kernelRows; ++m) {
                for (int n = 0; n < kernelCols; ++n) {
                    sum += input[i + m][j + n] * kernel[m][n];
                }
            }
            output[i][j] = sum; // Store the result in the output matrix
        }
    }
}

// Function to print a 2D matrix
void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example 5x5 input matrix (image)
    int input[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Example 3x3 kernel (filter)
    int kernel[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // Output matrix will store the result of convolution
    int output[3][3];

    // Perform the convolution
    convolve2D(input, kernel, output);

    // Print the result
    cout << "Output after 2D Convolution:" << endl;
    printMatrix(output);

    return 0;
}
