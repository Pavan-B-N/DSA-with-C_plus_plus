#include <iostream>
#include <stack>
#include <algorithm> // Include the algorithm library
using namespace std;

/*
Rules
1.tarverse from the end
2.if ")" directly push to stack
3.if "(" pop and add until open closing parenthesis found
4.if equal precedence check associativity
    L-R : directly push
    R-L : pop and add
5.reverse the prefix expression to get actuall prefix expression
 */

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

string toPrefix(const string &infix)
{
    string prefix;
    stack<char> stack;
    // we can traverse the string in reverse order
    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char symbol = infix[i];
        if (isspace(symbol))
        {
            continue;
        }
        else if (isalnum(symbol))
        {
            prefix += symbol;
        }
        else if (symbol == ')')
        {
            stack.push(symbol);
        }
        else if (symbol == '(')
        {
            while (stack.top() != ')')
            {
                prefix += stack.top();
                stack.pop();
            }

            stack.pop();
        }
        else
        {
            while (!stack.empty() && stack.top() != ')' && prec(symbol) < prec(stack.top()))
            {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(symbol);
        }
    }

    while (!stack.empty())
    {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix = "A+B";
    cout << "Infix Expression: " << infix << endl;

    string result = toPrefix(infix);
    cout << "Prefix Expression: " << result << endl;

    return 0;
}