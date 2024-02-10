#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>

using namespace std;

int evaluatePrefix(const string& str) {
    stack<int> stack;
    char ch;

    for (int i = 0; i < str.length(); i++) {
        ch = str[i];

        if (isspace(ch)) {
            continue;
        } else if (isalpha(ch)) {
            cout << "Alphabets are not allowed" << endl;
            exit(0);
        } else if (isdigit(ch)) {
            int n = 0;
            while (isdigit(ch)) {
                // n = n * 10 + static_cast<int>(c - '0');
                n = n * 10 + (int)(ch - '0');//Note is always returns a ascii value
                i++;
                ch = str[i];
            }
            i--;
            stack.push(n);
        } else {
            int y = stack.top();
            stack.pop();
            int x = stack.top();
            stack.pop();

            int res = 0;
            switch (ch) {
                    case '+': res = x + y; break;
                    case '-': res = x - y; break;
                    case '*': res = x * y; break;
                    case '/': res = x / y; break;
                    case '%': res = x % y; break;
                    case '^': res = x ^ y; break;
                    default:
                        cout << "Invalid operator encountered." << endl;
                        exit(0);
                }

            stack.push(res);
        }
    }

    return stack.top();
}

int main() {
    string input = "20 30  -";//a+b*c
    cout << "Postfix Expression: " << input << endl;
    cout << "Result: " << evaluatePrefix(input) << endl;

    return 0;
}
