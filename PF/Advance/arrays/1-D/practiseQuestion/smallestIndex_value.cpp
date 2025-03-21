/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-07-14.  
           
  TIME: 7:05 PM.
*/
/**Write a C11 program that declares an array alpha of 50 components
of type double. Initialize the array so that the first 25 components are
equal to the square of the index variable, and the last 25 components
are equal to three times the index variable. Output the array so that
10 elements per line are printed.*/
/*
#include <iostream>
#include "cmath"
using namespace std;


int main() {

    double alpha [50];

    for (int i=0 ; i<25 ;i++){
        alpha[i]=pow((i+1),2);
    }
    for (int i=25 ; i<50 ;i++){
        alpha[i]=pow((i+1),3);
    }

    //display
    for (int i=0 ; i<50 ;i++){
        cout << alpha[i] << endl;
    }
    return 0;
}
*/




#include <iostream>
#include "cmath"
using namespace std;
int smallestIndex(int arr[],int size){
    int s_indexElement = arr[0];
    int s_index = 0;
    for (int i=1 ; i<6 ;i++){
        if (arr[i]<s_indexElement){
            s_indexElement=arr[i];
            s_index=i;
        }
    }
    cout <<"element:" << s_indexElement << endl << "index:";
    return s_index;
}
int main() {

    int alpha [6]={5,9,4,35,45,43};
    cout << smallestIndex( alpha , 6);




    return 0;
}
