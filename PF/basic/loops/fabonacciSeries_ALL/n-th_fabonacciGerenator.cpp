#include <iostream>
using namespace std;

int main() {
   int index_a = 0;
   int index_b = 1;
   int index_x; // supporting index
   int range;

   cout << "Enter n-th value: ";
   cin >> range;

   cout << index_a << "," << index_b ;

   for(int i=1 ; i<=range ; i++) {
       index_x = index_a + index_b;
       cout << "," << index_x ;
       // updating variables
       index_a = index_b;
       index_b = index_x;
   }
    return 0;
}

/*
fabonacci series : 0,1,1,2,3,5,8,13,21,...
*/