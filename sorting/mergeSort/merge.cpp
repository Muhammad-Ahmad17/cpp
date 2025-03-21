/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-10-11.  
           
  TIME: 11:52 AM.
*/
/*
#include <iostream>
using namespace std;

void merge(int arr[],int start, int end)
{
    int mid = (start + end)/2;

    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *firstPart = new int[length1];
    int *secondPart = new int[length2];

    int mainArrayIndex = start;
    for ( int i = 0; i < length1; i++){
        firstPart[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for ( int j = 0; j < length2; j++){
        secondPart[j] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    while ( (index1 < length1 && index2 < length2)){
        if(firstPart[index1] < secondPart[index2])
            arr[mainArrayIndex++] = firstPart[index1++];
        else
            arr[mainArrayIndex++] = secondPart[index2++];
    }

    while (index1 < length1){
        arr[mainArrayIndex++] = firstPart[index1++];
    }
    while (index2 < length2){
        arr[mainArrayIndex++] = secondPart[index2++];
    }

    delete[] firstPart;
    delete[] secondPart;
}

void mergeSort(int arr[],int start, int end){

    if(start >= end) return;

    int mid = (start+end)/2;

    mergeSort(arr,start,mid);

    mergeSort(arr,mid+1,end);

    merge(arr,start,end);

}

int main(){
    int arr[] = {38,27,43,3,9,82,10};
    mergeSort(arr,0,6);

    for ( int i = 0; i < 7; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}*/

#include "iostream"
using namespace std;

void merge(int a[],int l1,int b[],int l2,int c[],int l){
    int i=0,j=0,k=0;
    while(i<l1 && j<l2){
        if(a[i]<b[j]){
            c[k++]=a[i++];
        }else{
            c[k++]=b[j++];
        }
    }
    for(;i<l1;i++)
        c[k++]=a[i++];
    for(;j<l2;j++)
        c[k++]=b[j++];
}

int main(){
    int arr1[4]={2,8,15,18};
    int arr2[4]={5,9,12,17};
    int arr[8]={};
    merge(arr1,4,arr2,4,arr,8);

    for (int i=0;i<8;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}