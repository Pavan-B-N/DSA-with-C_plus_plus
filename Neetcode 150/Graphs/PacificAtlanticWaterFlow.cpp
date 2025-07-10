// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>
using namespace std;

class Solution
{
public:
    int m, n;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // DFS from Pacific Ocean (top row and left column)
        for (int i = 0; i < m; ++i)
            dfs(heights, pacific, i, 0);
        for (int j = 0; j < n; ++j)
            dfs(heights, pacific, 0, j);

        // DFS from Atlantic Ocean (bottom row and right column)
        for (int i = 0; i < m; ++i)
            dfs(heights, atlantic, i, n - 1);
        for (int j = 0; j < n; ++j)
            dfs(heights, atlantic, m - 1, j);

        // Collect cells reachable from both oceans
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int row, int col)
    {
        visited[row][col] = true;

        // Direction vectors: Up, Left, Right, Down
        int rowNbr[4] = {-1, 0, 0, 1};
        int colNbr[4] = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            int newRow = row + rowNbr[k];
            int newCol = col + colNbr[k];

            if (isSafe(newRow, newCol, heights[row][col], heights, visited))
            {
                dfs(heights, visited, newRow, newCol);
            }
        }
    }

    // Helper to check if moving to (newRow, newCol) is valid
    bool isSafe(int newRow, int newCol, int prevHeight,
                vector<vector<int>> &heights,
                vector<vector<bool>> &visited)
    {
        return (newRow >= 0 && newRow < m &&
                newCol >= 0 && newCol < n &&
                !visited[newRow][newCol] &&
                heights[newRow][newCol] >= prevHeight);
    }
};
