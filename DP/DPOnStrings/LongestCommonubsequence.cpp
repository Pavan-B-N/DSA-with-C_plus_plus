// https://leetcode.com/problems/longest-common-subsequence/
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return computeLCS(n - 1, m - 1, s, t, dp);
    }

    // memoization
    // time complexity : o(N * M)
    int computeLCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // match
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + computeLCS(i - 1, j - 1, s1, s2, dp);

        int noMatchS1 = computeLCS(i - 1, j, s1, s2, dp);
        int noMatchS2 = computeLCS(i, j - 1, s1, s2, dp);

        return dp[i][j] = max(noMatchS1, noMatchS2);
    }
};

// tabulation
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
