#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is alphanumeric
bool isAlphanumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}
// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
// Function to convert infix expression to postfix
string infixToPostfix(const string& expression) {
    stack<char> stack;
    string postfix;
//1:isalnum>addtostring
//2:is'('>pushtostack
//3:is')'>first addtostring then pop untill stack empty or '(' comes
//4:is'+-*/'while stacknotempty and top.precedence>=ch.precedence
// addtostring>stack.top>pop>then push ch
// while stack not empty push to addtostring and then pop

    for (char ch : expression) {
        // If the character is an operand (alphanumeric), add it to postfix output
        if (isalnum(ch)) {
            postfix += ch;
        }
            // If the character is '(', push it to the stack
        else if (ch == '(') {
            stack.push(ch);
        }
            // If the character is ')', pop and add to postfix until '(' is found
        else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        }
            // If the character is an operator
        else if (isOperator(ch)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch) && ch != '^') {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    // Pop all the operators left in the stack
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << "Infix Expression: " << infix << "\n";
    cout << "Postfix Expression: " << postfix << "\n";
    return 0;
}
