#include <iostream>
using namespace std;

int factorial (int);        // not imp to give parameter
int nPr (int , int);
int nCr(int , int);

int main() {
    int n,r;
    cout << "Enter n and r to find permutation and combination:"; cin >> n >> r;

    cout << n << "P" << r << "=" <<  nPr ( n, r);
    cout << endl;
    cout << n << "C" << r << "=" <<  nCr ( n, r);

    return 0;
}

int factorial (int n) {
    int factorIal=1;
    for (int i=1 ; i<=n ; i++){
        factorIal*=i;
    }
    return factorIal;
}
int nPr (int n , int r) {
    return factorial(n)/ factorial(n-r);
}
int nCr(int n, int r) {
   // return factorial(n) / (factorial(r) * factorial(n - r));
   return nPr(n,r)/ factorial(r);
}

