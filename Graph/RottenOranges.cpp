// https://leetcode.com/problems/rotting-oranges/description/
/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        const int m = grid[0].size();

        typedef pair<int, int> Node; //{row,col}
        queue<pair<Node, int>> q;    //{node,time_to_rot}
        vector<vector<int>> visited(n, vector<int>(m, false));

        int time_to_rotten = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty())
        {
            auto node = q.front().first;
            int row = node.first;
            int col = node.second;
            auto time = q.front().second;
            time_to_rotten = max(time_to_rotten, time);
            q.pop();

            int drow[4] = {-1, 0, 1, 0};
            int dcol[4] = {0, +1, 0, -1};

            for (int k = 0; k < 4; k++)
            {
                int nrw = row + drow[k];
                int ncl = col + dcol[k];

                if (isSafe(nrw, ncl, n, m, grid, visited))
                {
                    q.push({{nrw, ncl}, time + 1});
                    visited[nrw][ncl] = true;
                }
            }
        }

        // chck is their any cell left having 2
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // we must need to make use of visited
                // because we ae not modifying the input instead we are marking visited as true
                if (!visited[i][j] && grid[i][j] == 1)
                    return -1;
            }
        }
        return time_to_rotten;
    }

    bool isSafe(int row, int col, int n, int m, vector<vector<int>> &grid,
                vector<vector<int>> &visited)
    {
        return row >= 0 && row < n && col >= 0 && col < m &&
               !visited[row][col] && grid[row][col] == 1;
    }
};