// https://leetcode.com/problems/shortest-path-in-binary-matrix/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// dijkstra algo
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        int rowN[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int colN[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        // distance matrix: store shortest distance from start to each cell
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        // priority queue holds tuples: (distance, row, col)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});//(distance, row, col)

        while (!pq.empty()) {
            auto [steps, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1)
                return steps+1;

            // dist also keep tracks of the visited status
            if (steps > dist[r][c])
                continue; // outdated entry

            for (int k = 0; k < 8; k++) {
                int nr = r + rowN[k];
                int nc = c + colN[k];

                // check edges, isSafe
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0) {
                    int newDist = steps + 1;
                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        pq.push({newDist, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};




// This solution doesn't work correctly for shortest path problems
// because BFS is the best approach for shortest paths in unweighted graphs.
// DFS—even with memoization—can cause TLE and produce incorrect answers
// because it may explore longer paths first and memoize suboptimal results.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int result = dfs(n - 1, n - 1, grid, visited);
        return result == INT_MAX ? -1 : result;
    }

    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<bool>>& visited) {
        if (row == 0 && col == 0)
            return 1;

        visited[row][col] = true;

        int rowN[] = {-1,-1,-1,0,0,1,1,1};
        int colN[] = {-1,0,1,-1,1,-1,0,1};

        int minSteps = INT_MAX;

        for (int k = 0; k < 8; ++k) {
            int newRow = row + rowN[k];
            int newCol = col + colN[k];

            if (isSafe(newRow, newCol, grid, visited)) {
                int subPath = dfs(newRow, newCol, grid, visited);
                if (subPath != INT_MAX)
                    minSteps = min(minSteps, subPath + 1);
            }
        }

        visited[row][col] = false;  // Backtrack

        return minSteps;
    }

    bool isSafe(int row, int col, vector<vector<int>>& grid,
                vector<vector<bool>>& visited) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               grid[row][col] == 0 && !visited[row][col];
    }
};
