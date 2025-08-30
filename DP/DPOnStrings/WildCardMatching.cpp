// https://leetcode.com/problems/wildcard-matching/description/
// ? = matches with single character
// * = matches with sequence of characters 0 or more
/*
s1="?ay"
s2="ray"
s2 matches s1 pattern
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return match(m - 1, n - 1, s, p, dp);
    }

private:
    bool match(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // both strings finished
        if (i < 0 && j < 0)
            return true;

        // pattern finished but string not
        if (j < 0 && i >= 0)
            return false;

        // string finished but pattern not — only matches if '*' left in pattern
        if (i < 0)
        {
            if (p[j] == '*')
                return match(i, j - 1, s, p, dp);
            return false;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[j] == s[i] || p[j] == '?')
        {
            return dp[i][j] = match(i - 1, j - 1, s, p, dp);
        }
        else if (p[j] == '*')
        {
            // empty sequence OR consume one character or more
            return dp[i][j] = (match(i, j - 1, s, p, dp) || match(i - 1, j, s, p, dp));
        }

        return dp[i][j] = false;
    }
};

// tabulation
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // base case
        dp[0][0] = true;
        // string finished but pattern not — only matches if '*' left in pattern
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // zero time or more
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};