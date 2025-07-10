// https://leetcode.com/problems/rotting-oranges/
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return -1;
        }
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q; //{row,col},timetorotten

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 2)
                { // rotten orange
                    q.push({{row, col}, 0});
                }
            }
        }
        int totalTime = 0;

        while (!q.empty())
        {
            auto [cell, time] = q.front();
            auto [row, col] = cell;
            q.pop();

            totalTime = max(totalTime, time);

            int rowNbr[] = {-1, 0, 0, 1};
            int colNbr[] = {0, -1, 1, 0};

            for (int k = 0; k < 4; k++)
            {
                int newRow = row + rowNbr[k];
                int newCol = col + colNbr[k];

                if (isSafe(newRow, newCol, grid))
                {
                    grid[newRow][newCol] = 2; // mark fresh orange as rotten
                    q.push({{newRow, newCol}, time + 1});
                }
            }
        }

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    return -1;
                }
            }
        }

        return totalTime;
    }

    bool isSafe(int row, int col, vector<vector<int>> &grid)
    {
        return row >= 0 && row < grid.size() && col >= 0 &&
               col < grid[0].size() && grid[row][col] == 1;
    }
};