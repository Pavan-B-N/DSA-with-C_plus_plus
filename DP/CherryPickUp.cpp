// https://leetcode.com/problems/cherry-pickup-ii/description/
/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/
// leetcode hard problem
#include <iostream>
#include <vector>
using namespace std;

int cherryPickup(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return helper(0, 0, c - 1, grid, dp);
}

// Time & Space Complexity = O(M*N*N)
int helper(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int r = grid.size();
    int c = grid[0].size();
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
    {
        return -1e9;
    }

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1]; // or j2
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }

    // explore all paths of robot1 and robot2 simultaneously
    int maxi = 0;
    // d= delat
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            // for every step of robot1, robot2 can take 3 differnt direction
            // so there are 9 steps
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += helper(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
