#include <iostream>
using namespace std;

int factorial (int n);

int main() {
    int num;
    cout << "Enter number to find factorial:"; cin >> num;

    cout << num << "!=" << factorial( num);

    return 0;
}

int factorial (int n){
    int factorIal=1;
    for (int i=1 ; i<=n ; i++){
        factorIal*=i;
    }
    return factorIal;
}