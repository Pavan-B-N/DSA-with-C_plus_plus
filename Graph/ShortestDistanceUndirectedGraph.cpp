// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // code here
        // bfs
        queue<int> q; 
        int V = adj.size();
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] != INT_MAX)
            {
                for (auto v : adj[u])
                {
                    if (dist[u] + 1 < dist[v])
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        for (auto &ele : dist)
        {
            if (ele == INT_MAX)
            {
                ele = -1;
            }
        }

        return dist;
    }
};