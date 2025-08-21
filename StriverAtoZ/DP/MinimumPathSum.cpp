// https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// T.C  = o(N*M)
// S.C = pathlength (stack) + dp
// Memoization
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getMinPathSum(m - 1, n - 1, grid, dp);
    }
    int getMinPathSum(int i, int j, vector<vector<int>> &grid,
                      vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return INT_MAX;
        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = getMinPathSum(i - 1, j, grid, dp);
        int left = getMinPathSum(i, j - 1, grid, dp);
        return dp[i][j] = grid[i][j] + min(up, left);
    }
};

// tabulation
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = grid[0][0];
                    continue;
                }
                int up = i > 0 ? dp[i - 1][j] : INT_MAX;
                int left = j > 0 ? dp[i][j - 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
};