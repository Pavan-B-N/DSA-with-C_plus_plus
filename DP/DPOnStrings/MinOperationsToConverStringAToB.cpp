// https://leetcode.com/problems/delete-operation-for-two-strings/description/
#include <vector>
#include <string>
using namespace std;

/// minimum insertions or deletions to convert string A to B such that A==B

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int lcs = longestCommonSubsequence(word1, word2);
        int n = word1.length();
        int m = word2.length();
        return n + m - 2 * lcs;
    }
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // shift index method
                // n-1 = n, -1 = 0
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};