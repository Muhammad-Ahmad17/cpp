/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-10.  
           
  TIME: 10:34 PM.
*/
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int arraySize = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    cout << "The size of the array is: " << arraySize << endl;

    return 0;
}
/*size of array = total element * 4 -> integer is of 4
 sizeof(arr[0]) = 4 -> its basically one index size which we know for integer is 4
 also arr[0] is the base address of the array we can access all elements of arr by adding offset of sizeof(arr[0]){4 in case}
  */