
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

        queue<pair<pair<int, int>, int>> q; //{row,col},distance
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }

        int rowNbr[] = {0, 0, -1, 1};
        int colNbr[] = {-1, 1, 0, 0};

        // bfs
        while (!q.empty())
        {
            auto [row, col] = q.front().first;
            int dis = q.front().second;
            q.pop();
            mat[row][col] = dis;

            for (int k = 0; k < 4; k++)
            {
                int newRow = row + rowNbr[k];
                int newCol = col + colNbr[k];

                if (isSafe(mat, newRow, newCol, visited))
                {
                    q.push({{newRow, newCol}, dis + 1});
                    visited[newRow][newCol] = true;
                }
            }
        }

        return mat;
    }
    bool isSafe(vector<vector<int>> &mat, int row, int col, vector<vector<bool>> &visited)
    {
        int m = mat.size();
        int n = mat[0].size();
        return row >= 0 && row < m && col >= 0 && col < n && !visited[row][col];
    }
};