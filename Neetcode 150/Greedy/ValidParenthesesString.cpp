// https://leetcode.com/problems/valid-parenthesis-string/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> openStack, starStack;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                openStack.push(i);
            }
            else if (ch == '*')
            {
                starStack.push(i);
            }
            else if (ch == ')')
            {
                if (!openStack.empty())
                {
                    openStack.pop(); // match with '('
                }
                else if (!starStack.empty())
                {
                    starStack.pop(); // match with '*'
                }
                else
                {
                    return false; // no match
                }
            }
        }

        // Match remaining '(' with '*' to the right
        while (!openStack.empty() && !starStack.empty())
        {
            int openIndex = openStack.top();
            int starIndex = starStack.top();
            if (openIndex < starIndex)
            {
                openStack.pop();
                starStack.pop();
            }
            else
            {
                return false; // '*' appears before '(', can't balance
            }
        }

        return openStack.empty(); // valid only if no unmatched '(' left
    }
};

class Solution
{
public:
    bool checkValidString(string s)
    {
        int minOpen = 0, maxOpen = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                minOpen++;
                maxOpen++;
            }
            else if (ch == ')')
            {
                minOpen--;
                maxOpen--;
            }
            else
            {              // ch == '*'
                minOpen--; // treat * as ')'
                maxOpen++; // treat * as '('
            }

            if (maxOpen < 0)
                return false;
            minOpen = max(minOpen, 0);
        }
        return minOpen == 0;
    }
};
