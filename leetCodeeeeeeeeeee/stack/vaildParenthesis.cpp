#include <iostream>
#include "stack"
using namespace std;

bool is1Valid (string exp){
    stack<char>stack;
    for (char ch : exp){
        if(ch=='('||ch=='{'||ch=='['){
            stack.push(ch);
        }else{
            if(stack.empty()){
                return false;
            }
            if((ch == ')' && stack.top() == '(')||
               (ch == '}' && stack.top() == '{')||
               (ch == ')' && stack.top() == '(')){
                stack.pop();
            }else{
                return false;
            }
        }
    }
    return stack.empty();
}
bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // If it's an opening bracket, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
            // If it's a closing bracket, check for a match with the top of the stack
        else {
            if (st.empty()) return false; // Stack empty, no matching opening bracket

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();  // Pop the matching open bracket
            } else {
                return false;  // Mismatch found
            }
        }
    }
    return st.empty();  // If stack is empty, it's valid
}
int main() {
    char arr[] = "({()})";
    if(is1Valid(arr)){
        cout << "Given braces are in valid order";
    }else{
        cout << "Given braces are not in valid order";
    }
    return 0;
}

bool is3Valid(string s){
    stack<char>stack ;
    for (char ch:s) {
        if (ch == '(' || ch == '{' || ch == '['){
            stack.push(ch);
        }else {
            if(stack.empty()) return false;
            char top=stack.top();
            if ((ch == ')' && top == '(') ||
            (ch == '}' && top == '{') ||
            (ch == ']' && top == '[')) {
                stack.pop();
            }
        }

    }
}