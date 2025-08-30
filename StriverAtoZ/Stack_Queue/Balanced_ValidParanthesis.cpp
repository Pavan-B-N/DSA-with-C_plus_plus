#include <iostream>
#include <stack>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/
// o(n)
class Solution
{
public:
    bool isValid(string &str)
    {
        stack<char> charStack;

        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                charStack.push(ch);
            }
            else if (!charStack.empty() && ((charStack.top() == '(' && ch == ')') ||
                                            (charStack.top() == '{' && ch == '}') ||
                                            (charStack.top() == '[' && ch == ']')))
            {
                charStack.pop();
            }
            else
            {
                return false;
            }
        }
        return charStack.empty();
    }
};