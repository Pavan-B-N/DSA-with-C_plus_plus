// https://leetcode.com/problems/number-of-islands/
#include <vector>
using namespace std;

/*
Time Complexity: O(m * n) — you visit each cell at most once.
Space Complexity: O(m * n) — for the visited array and recursion stack (in worst case of large island).
*/
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        int islands = 0;
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

    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
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

    bool isSafe(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        return row >= 0 && row < grid.size() && col >= 0 &&
               col < grid[0].size() && grid[row][col] == '1' &&
               !visited[row][col];
    }
};