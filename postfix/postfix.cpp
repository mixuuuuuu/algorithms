#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int operation(int operand1, int operand2, char op) {
    switch (op) {
        case'+':
            return operand1 + operand2;
        case'-':
            return operand1 - operand2;
        case'*':
            return operand1 * operand2;
        case'/':
            return operand1 / operand2;
        default:
            cerr << "Error:Invalid operator!" << endl;
            return 0;
    }
}

int evaluatePostfixExpression(const string& postfix) {
    stack<int> operands;
    stringstream ss(postfix);
    string token;
    while (ss >> token) {
        if (!isOperator(token[0]) && token[0] != '=') {
            //如果是数字，则转换为整数，入栈
            operands.push(stoi(token));
        }
        else if(token[0] != '=') {
            //如果是运算符，弹出两个数，运算后将结果入栈
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operation(operand1, operand2, token[0]));
        }
        if (token[0] == '=') {
            return operands.top();
        }
    }
    return operands.top();
}

int main()
{ 
    string postfix;
    getline(cin, postfix);
    int result = evaluatePostfixExpression(postfix);
    cout << result << endl;
    return 0;
}