// https://leetcode.com/problems/distinct-subsequences/description/

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabb-it
ra-bbit
rab-bit

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
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findDistinctSubsequences(m - 1, n - 1, s, t, dp);
    }
    int findDistinctSubsequences(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int pick = 0;
        if (s[i] == t[j])
        {
            pick = findDistinctSubsequences(i - 1, j - 1, s, t, dp);
        }
        // no match
        int notPick = findDistinctSubsequences(i - 1, j, s, t, dp);
        return dp[i][j] = pick + notPick;
    }
};

// tabulation
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int pick = 0;
                if (s[i - 1] == t[j - 1])
                {
                    pick = dp[i - 1][j - 1];
                }
                int notPick = dp[i - 1][j];
                // The test cases are generated so that the answer fits on a 32-bit signed integer.
                // hence no need to use unsigned long long for the entire DP which is costly
                // dp[i][j]=pick+notPick
                dp[i][j] = min((unsigned long long)INT_MAX, (unsigned long long)pick + notPick);
            }
        }
        return dp[m][n];
    }
};