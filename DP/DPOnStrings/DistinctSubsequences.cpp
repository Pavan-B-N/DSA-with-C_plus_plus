// https://leetcode.com/problems/distinct-subsequences/description/

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findDistinctSubsequencesOfT(n - 1, m - 1, s, t, dp);
    }
    int findDistinctSubsequencesOfT(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            int pick = findDistinctSubsequencesOfT(i - 1, j - 1, s, t, dp);
            int notPick = findDistinctSubsequencesOfT(i - 1, j, s, t, dp);
            return dp[i][j] = pick + notPick;
        }

        // no match
        return dp[i][j] = findDistinctSubsequencesOfT(i - 1, j, s, t, dp);
    }
};

// tabulation
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
    // base case
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    // rest
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // shitft index method
            if (s[i - 1] == t[j - 1])
            {
                unsigned long long pick = dp[i - 1][j - 1];
                unsigned long long notPick = dp[i - 1][j];
                dp[i][j] = pick + notPick;
            }
            else
            {
                // no match
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
