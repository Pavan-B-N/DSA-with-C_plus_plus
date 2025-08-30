// https://leetcode.com/problems/minimum-falling-path-sum/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time: O(m*n) (Each (i,j) computed once)
// Space: O(m*n) for dp + recursion stack
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        // -100 <= matrix[i][j] <= 100
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); // store computed results

        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            minPathSum = min(minPathSum, getMinPathSum(m - 1, j, matrix, dp));
        }
        return minPathSum;
    }

    int getMinPathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (j < 0 || j >= n)
            return INT_MAX;

        // Base case: first row
        if (i == 0)
            return grid[0][j];

        // Already computed
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int up = getMinPathSum(i - 1, j, grid, dp);
        int leftDiagonal = getMinPathSum(i - 1, j - 1, grid, dp);
        int rightDiagonal = getMinPathSum(i - 1, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min({up, leftDiagonal, rightDiagonal});
    }
};

// tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        // -100 <= matrix[i][j] <= 100
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = matrix[0][j];
                    continue;
                }

                int up = dp[i - 1][j]; // always valid since i > 0 here
                int leftDiagonal = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int rightDiagonal = (j + 1 < n) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, leftDiagonal, rightDiagonal});
            }
        }

        int minPathSum = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            minPathSum = min(minPathSum, dp[m - 1][j]);
        }
        return minPathSum;
    }
};
