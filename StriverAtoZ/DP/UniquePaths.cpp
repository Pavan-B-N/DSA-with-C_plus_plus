// https://leetcode.com/problems/unique-paths/
#include <iostream>
#include <vector>
using namespace std;

// The robot can only move either down or right at any point in time.
// in reverse manner, down = up, right=left, because we are doing recursion starting from the point m-1,n-1
// Time Complexity = o(m*n)
// Space Complexity = O(m-1)+(n-1)+O(m+n))
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePaths(m - 1, n - 1, dp);
}
// memoization
int uniquePaths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = uniquePaths(i - 1, j, dp);
    int left = uniquePaths(i, j - 1, dp);
    return dp[i][j] = up + left;
}

// tabulation
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}