#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
using namespace std;

int evaluatePrefix(const string &str)
{
    stack<int> stack;
    char ch;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        ch = str[i];

        if (isspace(ch))
        {
            continue;
        }
        else if (isalpha(ch))
        {
            cout << "Alphabets are not allowed" << endl;
            exit(0);
        }
        else if (isdigit(ch))
        {
            int n = 0;
            int s = i;
            /*
                0 3
                s e
            */
            while (i < str.length() && isdigit(ch))
            {
                i--;
                ch = str[i];
            }
            i++;
            int e = i;
            for (int j = e; j <= s; j++)
            {
                n = n * 10 + (int)(str[j] - '0');
            }
            stack.push(n);
        }
        else
        {
            int x = stack.top();
            stack.pop();
            int y = stack.top();
            stack.pop();

            int res = 0;
            switch (ch)
            {
            case '+':
                res = x + y;
                break;
            case '-':
                res = x - y;
                break;
            case '*':
                res = x * y;
                break;
            case '/':
                res = x / y;
                break;
            case '%':
                res = x % y;
                break;
            case '^':
                res = x ^ y;
                break;
            default:
                cout << "Invalid operator encountered." << endl;
                exit(0);
            }
            stack.push(res);
        }
    }

    return stack.top();
}

int main()
{
    string input = "- 20 30"; // Infix expression: a-b
    cout << "Prefix Expression: " << input << endl;
    cout << "Result: " << evaluatePrefix(input) << endl;

    return 0;
}
