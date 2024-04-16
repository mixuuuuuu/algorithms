#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0; //括号返回0
}

bool isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')');
}

string infixToPostfix(const string& infix) {
    stack<char> operands;
    stringstream ss(infix);
    string tempNum;
    string postfix;
    //stringstream postfix;
    char token;
    while (ss>>token) {
        if (isdigit(token)) {
            //如果是数字，则添加到后缀表达式末尾
            tempNum.push_back(token);
        }
        else {
            if (!tempNum.empty()) {
                postfix += tempNum + ' ';
                tempNum.clear();
            }
            if (token == '(') {
                operands.push(token);
            }
            else if (token == ')') {
                while (!operands.empty() && operands.top() != '(') {
                    postfix.push_back(operands.top());
                    postfix.push_back(' ');
                    operands.pop();
                }
                if (operands.top() == '(') {
                    operands.pop();
                }
            }
            else if (token == '=') {
                continue;
            }
            else {
                //如果是运算符
                while (!operands.empty() && precedence(operands.top()) >= precedence(token)) {
                    postfix.push_back(operands.top());
                    postfix.push_back(' ');
                    operands.pop();
                }
                operands.push(token);
            }
        }
    }
    if (!tempNum.empty()) {
        postfix += tempNum + ' ';
        tempNum.clear();
    }
    while (!operands.empty()) {
        postfix.push_back(operands.top());
        postfix.push_back(' ');
        operands.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
	return 0;
}
