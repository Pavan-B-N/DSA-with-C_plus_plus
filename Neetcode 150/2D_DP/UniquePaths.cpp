// https://leetcode.com/problems/unique-paths/
#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    // The robot can only move either down or right at any point in time.
    // in reverse manner, down = up, right=left, because we are doing recursion
    // starting from the point m-1,n-1
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findUniquePaths(m - 1, n - 1, dp);
    }
    int findUniquePaths(int i, int j, vector<vector<int>> &dp)
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
        int up = findUniquePaths(i - 1, j, dp);
        int left = findUniquePaths(i, j - 1, dp);
        return dp[i][j] = up + left;
    }
};

// tabulation
class Solution
{
public:
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
};