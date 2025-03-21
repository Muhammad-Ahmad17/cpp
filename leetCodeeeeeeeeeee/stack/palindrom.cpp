#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s) {
        stack<char> stack;

        // Iterate through the string and process only alphanumeric characters
        for (char ch : s) {
            if (isalnum(ch)) {

                // Convert to lowercase to ensure case-insensitive comparison
                ch = tolower(ch);
                // Remove the middle character if the string length is odd
                if (s.size() % 2 != 0) {
                    int mid = s.length() / 2;
                    s.erase(mid, 1);
                }
                if (!stack.empty() && stack.top() == ch) {
                    stack.pop();
                } else {
                    stack.push(ch);
                }
            }
        }

        // If the stack is empty, the string is considered a palindrome
        return stack.empty();
    }
};

int main() {
    Solution sol;
    string s = "Amanaplanacanal Panama";
    if (sol.isPalindrome(s)) {
        cout << "\"" << s << "\" is a palindrome after filtering and ignoring case." << endl;
    } else {
        cout << "\"" << s << "\" is not a palindrome after filtering and ignoring case." << endl;
    }
    return 0;
}
