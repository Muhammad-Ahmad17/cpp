

#include <iostream>
using namespace std;

void decToBin(int num, int base)
{
    if (num > 0)
    {
        decToBin(num / base, base);
        cout << num % base;
    }
}

int main() {
    decToBin(17,2);

    return 0;
}
