#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str) {
    stack<char> st;

    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                return false; // More closing brackets than opening brackets
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    return st.empty(); // If stack is empty, all brackets are balanced
}

int main() {
    string str = "{[()]}";
    if (isBalanced(str)) {
        cout << "The parentheses in the string are balanced." << endl;
    } else {
        cout << "The parentheses in the string are not balanced." << endl;
    }

    return 0;
}