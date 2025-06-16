// https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTabValue=PROBLEM
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// memo
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1)); // initialize dp table
    int maxSum = INT_MIN;

    for (int j = 0; j < n; j++)
    {
        int sum = maxPathSum(m - 1, j, matrix, dp);
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int maxPathSum(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int m = matrix.size();
    int n = matrix[0].size();

    if (j < 0 || j >= n)
        return -INT_MAX; // out of bounds or we can return 1e9

    if (i == 0)
        return matrix[i][j]; // base case

    if (dp[i][j] != -1)
        return dp[i][j]; // return already computed value

    int up = maxPathSum(i - 1, j, matrix, dp);
    int upLeftDiagonal = maxPathSum(i - 1, j - 1, matrix, dp);
    int upRightDiagonal = maxPathSum(i - 1, j + 1, matrix, dp);

    return dp[i][j] = matrix[i][j] + max({up, upLeftDiagonal, upRightDiagonal});
}



// tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1)); // initialize dp table
    int maxSum = INT_MIN;

    for (int j = 0; j < n; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = dp[i - 1][j];
            int upLeftDiagonal = j > 0 ? dp[i - 1][j - 1] : -1e9;
            int upRightDiagonal = j < n - 1 ? dp[i - 1][j + 1] : -1e9;
            dp[i][j] = matrix[i][j] + max({up, upLeftDiagonal, upRightDiagonal});
        }
    }

    for (int j = 0; j < n; j++)
    {
        maxSum = max(maxSum, dp[m - 1][j]);
    }

    return maxSum;
}
