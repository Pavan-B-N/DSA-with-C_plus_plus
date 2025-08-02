// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
/*
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.
*/
#include <string>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int openBrackets = 0;
        int maxDepth = 0;
        for (char ch : s)
        {
            if (ch == '(')
                openBrackets++;
            else if (ch == ')')
                openBrackets--;
            maxDepth = max(maxDepth, openBrackets);
        }
        return maxDepth;
    }
};