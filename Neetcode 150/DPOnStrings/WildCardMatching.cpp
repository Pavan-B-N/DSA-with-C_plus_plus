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
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        // -1 = unvisited, 0 = false , 1 = true
        return wildCardMatch(n - 1, m - 1, s, p, dp);
    }

    bool wildCardMatch(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // i for string
        // j for pattern
        // if we proceesed all the patterns but still we have left with some string then its false else its true
        if (j < 0)
        {
            return i < 0;
        }

        if (i < 0 && j >= 0)
        {
            if (p[j] == '*')
            {
                return wildCardMatch(i, j - 1, s, p, dp);
            }
            return false;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = wildCardMatch(i - 1, j - 1, s, p, dp);
        }
        else if (p[j] == '*')
        {
            // zero time or more
            return dp[i][j] = wildCardMatch(i, j - 1, s, p, dp) || wildCardMatch(i - 1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }
};

// tabulation
bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    // base case
    dp[0][0] = true;
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