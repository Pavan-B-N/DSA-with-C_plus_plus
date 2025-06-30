// https://leetcode.com/problems/valid-parentheses/description/
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string &str)
    {
        stack<char> charStack;

        for (char ch : str)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                charStack.push(ch);
            }
            else if (!charStack.empty() &&
                     ((charStack.top() == '(' && ch == ')') ||
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