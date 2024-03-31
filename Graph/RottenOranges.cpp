
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    const int n = grid.size();
    const int m = grid[0].size();
    // queue for store {{row,col},timetorotten};
    queue<pair<pair<int, int>, int>> q;
    // visited matrix
    vector<vector<int>> visited(n, vector<int>(m));
    // traverse the matrix and store all rotten oragnes in queue
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
            else
                visited[i][j] = 0;
        }
    }
    // now traverse in all four direction the queue to get maximum time for all rotten orange
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, +1, 0, -1};
    int time_to_rotten = 0;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
 
        time_to_rotten = max(time_to_rotten, t);
        q.pop();
        // move around in all four directions
        for (int i = 0; i < 4; i++)
        {
            int nrw = r + drow[i];
            int ncl = c + dcol[i];

            // boundary cases
            if (nrw >= 0 && nrw < n && ncl >= 0 && ncl < m && visited[nrw][ncl] != 2 && grid[nrw][ncl] == 1)
            {
                q.push({{nrw, ncl}, t + 1});
                visited[nrw][ncl] = 2;
            }
        }
    }
    // chck is their any cell left having 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] != 2 && grid[i][j] == 1)
                return -1;
        }
    }
    return time_to_rotten;
}