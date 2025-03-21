/*******************************
 * Copyright (c) 2024          *
 *                             *
 * Name: MUHAMMAD AHMAD.       *
 *                             *
 * Project Name: PF.          *
 *                             *
 * Date: 2024-06-26.           *
 *******************************/
#include <iostream>
using namespace std;

int dotCountInTriangle(int NthLengthTriangle){
    int totalDots=0;
    for (int i=1 ; i <=NthLengthTriangle ; i++){
        totalDots +=i ;
    }
    return totalDots;
}


int main() {
    cout << "dot count of specific triangle:";
    cout << dotCountInTriangle(6);

    cout << "\ndot count of series\n";
    int finalRange;
    cout << "enter final range:"; cin >> finalRange;

    int i=1;
    for (i; i <= finalRange ; i++){
        cout << dotCountInTriangle(i) << "\n";
    }


    return 0;

}

/*
*         1_1

 *          2_3
* *

    *          4_10
   * *
  * * *
 * * * *
 */