// https://leetcode.com/problems/triangle/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m); // dynamic in nature
        // initializing variable length dp
        for (int i = 0; i < m; i++)
        {
            dp[i].resize(triangle[i].size(), -1);
        }

        // start from the last row and call recursion
        int minPathSum = INT_MAX;
        for (int j = 0; j < triangle[m - 1].size(); j++)
        {
            int sum = getMinPathSum(triangle, m - 1, j, dp);
            minPathSum = min(minPathSum, sum);
        }
        return minPathSum;
    }
    int getMinPathSum(vector<vector<int>> &triangle, int i, int j,
                      vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return triangle[0][0];
        }
        // check for outbounds
        if (i < 0 || j < 0 || j >= triangle[i].size())
        {
            return INT_MAX; // infinity
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = getMinPathSum(triangle, i - 1, j, dp);
        int leftDiagonal = getMinPathSum(triangle, i - 1, j - 1, dp);

        return dp[i][j] = triangle[i][j] + min(up, leftDiagonal);
    }
};

// tabulation
int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    vector<vector<int>> dp(m);
    for (int i = 0; i < m; i++)
    {
        dp[i].resize(triangle[i].size());
    }

    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = triangle[0][0];
                continue;
            }

            int up = (i > 0 && j < dp[i - 1].size()) ? dp[i - 1][j] : 1e9;
            int diaLeft = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 1e9;

            dp[i][j] = triangle[i][j] + min(up, diaLeft);
        }
    }
    int minPathSum = INT_MAX;
    for (int j = 0; j < triangle[m - 1].size(); j++)
    {
        minPathSum = min(minPathSum, dp[m - 1][j]);
    }
    return minPathSum;
}