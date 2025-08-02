// https://leetcode.com/problems/string-to-integer-atoi/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int ans = 0;
        int sign = 1;
        solve(0, s, true, sign, ans);
        if (ans == INT_MIN)
            return ans; // _ INT_MIN * -1 = INT_MAX + 1 which is overflow
        return ans * sign;
    }

    void solve(int index, const string &s, bool isFirstPart, int &sign, int &ans)
    {
        if (index == s.size())
            return;

        char ch = s[index];

        if (isFirstPart && ch == ' ')
        {
            solve(index + 1, s, true, sign, ans);
            return;
        }

        if (isFirstPart && (ch == '+' || ch == '-'))
        {
            sign = (ch == '-') ? -1 : 1;
            solve(index + 1, s, false, sign, ans);
            return;
        }

        if (isdigit(ch))
        {
            int num = ch - '0';

            // Check overflow
            if (ans > (INT_MAX - num) / 10)
            {
                ans = sign == 1 ? INT_MAX : INT_MIN;
                return;
            }

            ans = ans * 10 + num;
            solve(index + 1, s, false, sign, ans);
        }
        // Stop on any other character
    }
};
