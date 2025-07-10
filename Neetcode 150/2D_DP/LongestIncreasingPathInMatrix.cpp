// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
#include <vector>
using namespace std;

class Solution
{
public:
    // No visited array is needed.
    // The increasing constraint ensures no cycles.
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLen = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maxLen = max(maxLen, dfs(i, j, matrix, dp));

        return maxLen;
    }

private:
    int rowNbr[4] = {-1, 0, 0, 1}; // up, left, right, down
    int colNbr[4] = {0, -1, 1, 0};

    int dfs(int row, int col, vector<vector<int>> &matrix,
            vector<vector<int>> &dp)
    {
        if (dp[row][col] != -1)
            return dp[row][col];

        int maxPath = 1;
        for (int k = 0; k < 4; ++k)
        {
            int newRow = row + rowNbr[k];
            int newCol = col + colNbr[k];
            if (isSafe(newRow, newCol, row, col, matrix))
            {
                maxPath = max(maxPath, 1 + dfs(newRow, newCol, matrix, dp));
            }
        }
        return dp[row][col] = maxPath;
    }

    bool isSafe(int newRow, int newCol, int currRow, int currCol,
                vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        return newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
               matrix[newRow][newCol] > matrix[currRow][currCol];
    }
};
