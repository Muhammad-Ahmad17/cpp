#include <iostream>
using namespace std;
//___________________________________________________________________
int linear1Search (const int arr[] , int len , int target, int index=0){
    if (index==len){
        cout << "element not found";
        return -1 ;
    }
    if (arr[index] == target) {
        cout << "your element " << target << " is at " << index << " index";
    }
    return linear1Search ( arr ,  len , target,  ++index);
}
//___________________________________________________________________

int main() {

    int a[5]={1,3,5,4,8};

    linear1Search(a,5,76);
//     print_array(a,5,nam);

    return 0;
}
