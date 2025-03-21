/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-16.  
           
  TIME: 10:46 PM.
*/
#include "iostream"
using namespace std;
void traverseArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " "; // Accessing elements using pointer arithmetic
    }
}
void partition (int* arr,int size,int*& left,int& leftSize,int*& right,int& rightSize){
    cout << "Main Array:";
    traverseArray(arr,size);
    cout << endl;

    int mid=size/2;
    leftSize=mid;
    rightSize=size-mid;

     left = new int [leftSize];
     right = new int [rightSize];

    for (int i=0; i<leftSize; ++i){
        *(left+i)=*(arr+i);
    }
    for (int j=0; j<rightSize; ++j){
        *(right + j)=*(arr+leftSize + j);
    }
}
int main(){
    int* array = new int [10];
    for (int i = 0; i < 10; ++i) {
        *(array + i) = 9 + i; // Fill with values from 9 to 18
    }

    int leftSize=0;
    int* leftarray = nullptr;
    int rightSize=0;
    int* rightarray = nullptr;

    partition(array, 10, leftarray, leftSize, rightarray, rightSize);
    cout << "1:\n";
    cout << "left Array:";
    traverseArray(leftarray,leftSize);
    cout << "\n2:\n";
    cout << "Right Array:";
    traverseArray(rightarray,rightSize);

    delete[] array;
    delete[] leftarray;
    delete[] rightarray;

    return 0;
}