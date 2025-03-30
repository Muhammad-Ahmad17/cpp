/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-24.  
           
  TIME: 4:27 AM.
*/

#include <iostream>
using namespace std;

void largestElement(const int arr[],int len){
    int first_max=0;
    int second_max=0;
    int third_max=0;
    for(int i=0 ; i<len ; i++){

        if(arr[i]>first_max){
            third_max = second_max;
            second_max = first_max;
            first_max = arr[i];
        } else if(arr[i]>second_max && arr[i]<first_max){
            third_max = second_max;
            second_max=arr[i];
        } else if(arr[i]>third_max && arr[i]<second_max){
            third_max=arr[i];
        }
    }
    cout << "1st_max:" << first_max << endl;
    cout << "2nd_max:" << second_max << endl;
    cout << "3rd_max:" << third_max << endl;
}
int main(){
    int array[]={2311,267,6463,44,5,3,1,7};
    int length =sizeof(array)/sizeof(array[1]);
    largestElement(array,length);

    return 0;
}