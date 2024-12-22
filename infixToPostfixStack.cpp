#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(string infix) {
    string postfix;
    stack<char> operators;

    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*c";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix <<endl;
    cout << "Postfix expression: " << postfix <<endl;

    return 0;
}