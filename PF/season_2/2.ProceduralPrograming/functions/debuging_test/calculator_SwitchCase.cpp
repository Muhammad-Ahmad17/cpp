#include <iostream>
using namespace std;

double getFirstValue(){
    double num1;
    cout << "Enter number:"; cin >> num1;
    return num1;
}
/*double getSecondValue(){
    double num2;
    cout << "Enter number 2:"; cin >> num2;
    return num2;
}*/
char getOperator(){
    char opr;
    cout << "Enter operator (+,-,*,/):"; cin >>opr;
    return opr;
}

double calculate (double a , char opr , double b){
    bool flag = true;
    switch (opr) {
        case '+':
            cout << a << " + " << b << endl;
            flag = false;
            return a+b;
            break;
        case '-':
            cout << a << " - " << b << endl;
            flag = false;
            return a-b;
            break;
        case '*':
            cout << a << " * " << b << endl;
            flag = false;
            return a*b;
            break;
        case '/':
            if (b != 0) {
                cout << a << " / " << b << endl;
            } else {
                cout << "Division by zero is not allowed." << endl;
            }
            flag = false;
            return a/b;
            break;
        default:
            cout << "Invalid operator. Please try again." << endl;
            flag = true;
    }
}

int main() {
    double a = getFirstValue();
    char opr = getOperator();
    double b = getFirstValue();

    double result = calculate( a, opr, b);

    cout << "Result:" << result << endl;
    return 0;
}