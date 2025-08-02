// https://leetcode.com/problems/remove-outermost-parentheses/
/*
Input: s = "(()())(())"
Output: "()()()"


Input: s = "(()())(())(()(()))"
Output: "()()()()(())"

Input: s = "()()"
Output: ""
*/
#include <string>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int counter = 0;
        for (char ch : s)
        {
            if (ch == ')')
                counter--;
            if (counter != 0)
            {
                ans += ch;
            }
            if (ch == '(')
                counter++;
        }
        return ans;
    }
};