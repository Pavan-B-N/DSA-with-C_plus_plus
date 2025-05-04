// https://leetcode.com/problems/detect-cycles-in-2d-grid/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j])
                {
                    // connected components
                    if (bfs(grid, visited, i, j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();
        int rowNbr[] = {0, 0, -1, 1};
        int colNbr[] = {-1, 1, 0, 0};

        queue<pair<pair<int, int>, pair<int, int>>> q; // {{currRow, currCol}, {parentRow, parentCol}}
        q.push({{row, col}, {-1, -1}});
        visited[row][col] = true;

        while (!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();
            int r = node.first, c = node.second;

            for (int k = 0; k < 4; ++k)
            {
                int newRow = r + rowNbr[k];
                int newCol = c + colNbr[k];

                if (isSafe(grid, visited, newRow, newCol, grid[r][c]))
                {
                    q.push({{newRow, newCol}, {r, c}});
                    visited[newRow][newCol] = true;
                }
                else if (detectCycle(newRow, newCol, parent.first, parent.second, grid, visited, grid[r][c]))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool detectCycle(int newRow, int newCol, int parentRow, int parentCol,
                     vector<vector<char>> &grid, vector<vector<bool>> &visited, char currentChar)
    {
        int m = grid.size(), n = grid[0].size();
        return checkIndexOutOfBounds(grid,newRow,newCol)  &&
               grid[newRow][newCol] == currentChar &&
               visited[newRow][newCol] &&
               !(newRow == parentRow && newCol == parentCol);
    }

    bool checkIndexOutOfBounds(vector<vector<char>> &grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    bool isSafe(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col, char parentChar)
    {
        int m = grid.size();
        int n = grid[0].size();
        return checkIndexOutOfBounds(grid,row,col)  &&
               !visited[row][col] && grid[row][col] == parentChar;
    }
};
