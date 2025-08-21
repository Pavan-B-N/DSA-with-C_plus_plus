// https://leetcode.com/problems/path-with-minimum-effort/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// dijkstra algo with pq
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        // 4-directional movement: up, down, left, right
        int rowN[] = {-1, 1, 0, 0};
        int colN[] = {0, 0, -1, 1};

        // effort[i][j] will hold the minimum effort required to reach (i,j)
        // similar to dist
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;

        using T = tuple<int, int, int>; // (effort, row, col)
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty())
        {
            auto [currEffort, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == m - 1)
                return currEffort;

            if (currEffort > effort[r][c])
                continue; // skip stale entry

            for (int k = 0; k < 4; ++k)
            {
                int nr = r + rowN[k];
                int nc = c + colN[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int eff = abs(heights[nr][nc] - heights[r][c]);
                    int maxEffort = max(currEffort, eff);
                    if (maxEffort < effort[nr][nc])
                    {
                        effort[nr][nc] = maxEffort;
                        pq.push({maxEffort, nr, nc});
                    }
                }
            }
        }

        return -1; // Not reachable
    }
};
