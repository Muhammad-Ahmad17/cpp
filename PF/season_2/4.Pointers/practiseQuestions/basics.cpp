/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-08-11.  
           
  TIME: 1:15 AM.
*/

#include <iostream>
using namespace std;

int main1() {
    // Modify the value of num through the pointer
    // Print the original variable and the value via pointer
    int num = 42;
    int *p = &num;

    cout << "value of num jo *p me pari ha : " << *p;
    cout << "\nnum : " << num ;

    *p = 23;

    cout << "\nvalue of num jo p say change hoi: " << *p;
    cout << "\nnum after changing  : " << num ;

    return 0;
}

int main2() {
    int a = 10;
    int b = 20;
    int *p;

    // Point p to a and modify a via p
    cout << "orignal a : " << a;
    p = &a;
    *p= 11;
    cout << "\nmodify a via p :" << *p;

    // Reassign p to b and modify b via p
    cout << "\norignal b : " << b;
    p = &b;
    *p= 21;
    cout << "\nmodify b via p :" << *p;
    // Print the values of a and b
    cout << "\na:" << a << "\tb:" << b;
    return 0;
}

int main3() {
    int x = 15;
    int y = 25;
    int *px = &x;
    int *py = &y;

    cout << "before swaping : " << "\nx=" <<x << "\ny=" <<y;
    int t = *px;
    *px = *py;
    *py =t;

    cout << "\nafter swaping : " << "\nx=" <<x << "\ny=" <<y;
    // Swap the values of x and y using pointers only
    // Print the swapped values of x and y

    return 0;
}

int main4() {
    int a;
    int *pInt;
    char *pChar;

    // Print the size of pInt and pChar using sizeof()

    cout << "size of pInt: " << sizeof(pInt) << " \nsize of pChar: " << sizeof(pChar);


    return 0;
}

int main5() {
    int *p = NULL;

    // Check if p is NULL, print a message, and then safely dereference if it's not NULL
    if (p==0){
        cout << "yellow";
        cout << "\n p:" << p;
    }
    return 0;
}

int main() {
    int a = 5;
    int b = 10;
    int *p1 = &a;
    int *p2 = &b;

    // Compare the pointers p1 and p2
    if (*p1==*p2){
        cout << "same";
    } else {
        cout << "no same";
    }
    // Print if they point to the same or different locations

    return 0;
}
