// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://www.naukri.com/code360/problems/longest-common-substring_1235207?leftPanelTabValue=SUBMISSION
#include <vector>
#include <string>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int lcs(string &str1, string &str2)
{
    // build dp table
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                // diagonal
                dp[i][j] = 1 + dp[i - 1][j - 1];

                // find max parallely
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;

        // check all pairs recursively
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxLen = max(maxLen, lcs(i, j, s1, s2, dp));
            }
        }

        return maxLen;
    }

private:
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            // characters match
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);
        }

        // mismatch: reset to 0
        return dp[i][j] = 0;
    }
};
