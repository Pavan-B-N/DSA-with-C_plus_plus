// https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) // starting cell blocked
    {
        return 0;
    }

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper(obstacleGrid, m - 1, n - 1, dp);
}

int helper(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = helper(obstacleGrid, i - 1, j, dp);
    int left = helper(obstacleGrid, i, j - 1, dp);

    return dp[i][j] = up + left;
}

// tabulation
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) // starting cell blocked
    {
        return 0;
    }

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
                continue;
            }

            int up = i > 0 ? dp[i - 1][j] : 0;
            int left = j > 0 ? dp[i][j - 1] : 0;

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}