// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://www.naukri.com/code360/problems/longest-common-substring_1235207?leftPanelTabValue=SUBMISSION
#include <vector>
#include <string>
#include <iostream>
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