// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
/*
Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 
*/
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int counter = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                st.push(ch);
            }
            else if (st.empty())
            {
                counter++;
            }
            else
            {
                st.pop();
            }
        }
        return st.size() + counter;
    }
};

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open = 0, additions = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                open++;
            }
            else
            {
                if (open > 0)
                    open--; // match with an open
                else
                    additions++; // need one '('
            }
        }
        return additions + open;
    }
};
