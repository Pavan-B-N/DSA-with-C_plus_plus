// infix to postfix using stack
/*
Rules
1.operands are directly added to the postfix expression
//operators
2.if open parentheses "(" then directly push into stack
3.if incoming operator is closing parentheses ")" is found then pop and add it to postfix until open parenthesis found
4.if the incoming operator has highest precedence than the top of the stack then dircetly push it into stack
5.if the incoming operator has lower precedence then pop and add it to postfix until operator precedence becomes higher then the peek of the stack or stack becomes empty or "(" ius found
finally push the operator into stcak
6.if precedence is equivalent check for associativity
    L-R : follow step 5
    R-L : directly push into stack
7.at the end pop all and add it to postfix

*/
// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
#include <iostream>
#include <stack>
using namespace std;

// Operator precedence
int prec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// Infix to postfix conversion
string toPostfix(string &infix)
{
    string postfix;
    stack<char> stack;

    for (char symbol : infix)
    {
        if (isspace(symbol))
        {
            continue;
        }
        else if (isalnum(symbol))
        { // alphanumeric character. i.e symbol
            postfix += symbol;
        }
        else if (symbol == '(')
        {
            stack.push(symbol);
        }
        else if (symbol == ')')
        {
            while (stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            // pop for '('
            stack.pop();
        }
        // opeartor
        else
        {
            while (!stack.empty() && stack.top() != '(' && prec(symbol) <= prec(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(symbol);
        }
    }

    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main()
{
    string infix = "A-B";

    cout << toPostfix(infix) << endl;

    return 0;
}
