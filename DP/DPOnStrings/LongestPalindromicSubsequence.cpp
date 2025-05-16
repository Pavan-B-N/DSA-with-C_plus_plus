// https://leetcode.com/problems/longest-palindromic-subsequence/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    // s is the actual string
    // t is the reverse(s)
    // so longestCommmonSubsequece(s,t) is always a longest palindromic string
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(n - 1, n - 1, s, t, dp);
    }

    int longestCommonSubsequence(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return 1 + longestCommonSubsequence(i - 1, j - 1, s1, s2, dp);
        }

        // not match
        int notMatchS1 = longestCommonSubsequence(i - 1, j, s1, s2, dp);
        int notMatchS2 = longestCommonSubsequence(i, j - 1, s1, s2, dp);

        return dp[i][j] = max(notMatchS2, notMatchS1);
    }
};

//  tabulation
// s is the actual string
// t is the reverse(s)
// so longestCommmonSubsequece(s,t) is always a longest palindromic string
int longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return longestCommonSubsequence(s, t);
}

int longestCommonSubsequence(string &s1, string &s2)
{
    int n = s1.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // shift index
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}
