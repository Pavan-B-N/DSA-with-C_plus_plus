
// https://leetcode.com/problems/01-matrix/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        typedef pair<int, int> Node;
        queue<pair<Node, int>> q; //{node{row,col},dist}
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
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
            int dist = q.front().second;
            mat[row][col] = dist;
            q.pop();

            int drow[] = {-1, 0, 0, 1};
            int dcol[] = {0, -1, 1, 0};

            for (int k = 0; k < 4; k++)
            {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if (isSafe(nrow, ncol, m, n, visited))
                {
                    q.push({{nrow, ncol}, dist + 1});
                    visited[nrow][ncol] = true;
                }
            }
        }

        return mat;
    }

    bool isSafe(int row, int col, int m, int n, vector<vector<bool>> &visited)
    {
        return row >= 0 && row < m && col >= 0 && col < n && !visited[row][col];
    }
};