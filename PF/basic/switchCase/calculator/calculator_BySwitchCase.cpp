#include <iostream>
using namespace std;

int main() {
    int a, b;
    char opr;
    bool flag = true;

    while (flag) {
        cout << "Enter 1st value, then operator, and then 2nd value: ";
        cin >> a >> opr >> b;

        switch (opr) {
            case '+':
                cout << a << " + " << b << " = " << a + b << endl;
                flag = false;
                break;
            case '-':
                cout << a << " - " << b << " = " << a - b << endl;
                flag = false;
                break;
            case '*':
                cout << a << " * " << b << " = " << a * b << endl;
                flag = false;
                break;
            case '/':
                if (b != 0) {
                    cout << a << " / " << b << " = " << a / b << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                flag = false;
                break;
            default:
                cout << "Invalid operator. Please try again." << endl;
                flag = true;
        }
    }

    return 0;
}
