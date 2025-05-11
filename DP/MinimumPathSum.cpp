// https://leetcode.com/problems/minimum-path-sum/
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() < 1) {
        return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return minPathSum(m - 1, n - 1, grid, dp);
}

// T.C  = o(N*M)
// S.C = pathlength (stack) + dp
// pathlength = (n-1)+(m-1)
int minPathSum(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    if (i < 0 || j < 0) {
        return INT_MAX;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    // Note: we cannot store grid value here, bacause if INT_MAX returns the adding even +1 causes buffer overflow
    long long int up = minPathSum(i - 1, j, grid, dp);
    long long int left = minPathSum(i, j - 1, grid, dp);
    dp[i][j] = grid[i][j] + min(up, left);
    return dp[i][j];
}


// tabulation
int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() < 1) {
        return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[0][0]=grid[0][0];
                continue;
            }
            int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
            int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
            dp[i][j] = grid[i][j] + min(left, up);
        }
    }

    return dp[m - 1][n - 1];
}

