#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> st;
    
    for (char c : expression) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            
            switch(c) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
            }
        }
    }
    
    return st.top();
}

int main() {
    string expression = "23*5+";
    cout << "Postfix expression: " << expression << endl;
    cout << "Result: " << evaluatePostfix(expression) << endl;
    
    return 0;
}