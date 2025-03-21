/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-09-20.  
           
  TIME: 3:06 AM.
*/
#include <iostream>
using namespace std;

void print_array (int arr[],int len , const char *name){
    cout << name << ": {";
    for (int i=0 ; i<=len-1 ; i++){
        cout  << arr[i] ;
        if (i==len-1) {} else cout << "," ;
    }
    cout << "}";
}
//___________________________________________________________________
void linearSearch (const int arri[] , int len , int target){
    bool flag = true;
    for (int i=0 ; i<=len-1 ; i++) {
        if (arri[i] == target) {
            cout << "your element " << target << " is at " << i << " index";
            flag=false;
        }
    }
    if (flag) cout << "element (" << target << ") not found :(";
}
//___________________________________________________________________


int main() {

    int a[10]={1,3,5,4,8,4,53,52,32,24};
    print_array(a,10,"Given array");

    int key;
    cout << "\nEnter key:";  cin >> key;

    linearSearch(a,10,key);


    return 0;
}
