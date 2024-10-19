#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>

bool areParenthesesBalanced(const std::string& expression) {
    std::stack<char> stack;
    for (char ch : expression) {
        if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            if (stack.empty()) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

std::string infixToPostfix(const std::string& expression) {
    std::stack<char> stack;
    std::string postfix;
    for (char ch : expression) {
        if (std::isdigit(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> stack;
    for (char ch : postfix) {
        if (std::isdigit(ch)) {
            stack.push(ch - '0');
        }
        else {
            int val2 = stack.top(); stack.pop();
            int val1 = stack.top(); stack.pop();
            switch (ch) {
            case '+': stack.push(val1 + val2); break;
            case '-': stack.push(val1 - val2); break;
            case '*': stack.push(val1 * val2); break;
            case '/': stack.push(val1 / val2); break;
            }
        }
    }
    return stack.top();
}

int main() {
    std::string expression;
    std::cout << "請輸入運算式: ";
    std::cin >> expression;


    return 0;
}