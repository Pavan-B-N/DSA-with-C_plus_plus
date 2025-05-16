// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minInsertions(string s)
    {
        int len = s.length();
        return len - longestPalindromeSubseq(s);
    }
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
};