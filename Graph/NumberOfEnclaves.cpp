/*
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/
// https://leetcode.com/problems/number-of-enclaves/description/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // 0 = sea
    // 1 = land
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // top and bottom rows
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1 && !visited[0][j])
            {
                dfs(grid, visited, 0, j);
            }
            if (grid[m - 1][j] == 1 && !visited[m - 1][j])
            {
                dfs(grid, visited, m - 1, j);
            }
        }

        // left and right col
        for (int j = 0; j < m; j++)
        {
            if (grid[j][0] == 1 && !visited[j][0])
            {
                dfs(grid, visited, j, 0);
            }
            if (grid[j][n - 1] == 1 && !visited[j][n - 1])
            {
                dfs(grid, visited, j, n - 1);
            }
        }

        int enclaves = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
    void dfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int row, int col)
    {
        visited[row][col] = true;
        int rowNbr[] = {0, 0, -1, 1};
        int colNbr[] = {-1, 1, 0, 0};

        for (int k = 0; k < 4; k++)
        {
            int nr = row + rowNbr[k];
            int nc = col + colNbr[k];

            if (isSafe(board, visited, nr, nc))
            {
                dfs(board, visited, nr, nc);
            }
        }
    }

    bool isSafe(vector<vector<int>> &board, vector<vector<bool>> &visited, int row, int col)
    {
        int m = board.size();
        int n = board[0].size();
        return row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && board[row][col] == 1;
    }
};