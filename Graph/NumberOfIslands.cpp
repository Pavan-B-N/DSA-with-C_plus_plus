/*
https://www.geeksforgeeks.org/find-the-number-of-islands-using-dfs/

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

'0's (Water) and '1's(Land)

Given a binary 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 4 islands.

Example:

Input: mat[][] = {{1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {1, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {1, 0, 1, 0, 0}}
Output: 4
*/

// The number of calls to DFS() gives the number of connected components

// https://leetcode.com/problems/number-of-islands/description/

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        int islands = 0;
        // You may assume all four edges of the grid are all surrounded by water.
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == '1' && !visited[row][col])
                {
                    dfs(row, col, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(int row, int col, vector<vector<char>> &grid,
             vector<vector<int>> &visited)
    {
        visited[row][col] = true;

        int rowNbr[] = {-1, 0, 0, 1};
        int colNbr[] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            int newRow = row + rowNbr[k];
            int newCol = col + colNbr[k];

            if (isSafe(newRow, newCol, grid, visited))
            {
                dfs(newRow, newCol, grid, visited);
            }
        }
    }

    bool isSafe(int row, int col, vector<vector<char>> &grid,
                vector<vector<int>> &visited)
    {
        return row >= 0 && row < grid.size() && col >= 0 &&
               col < grid[0].size() && grid[row][col] == '1' &&
               !visited[row][col];
    }
};