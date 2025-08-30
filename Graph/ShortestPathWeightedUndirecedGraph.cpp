// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// find the path from 1 to N
// 1 based indexing
// output format : [distance, ..path]
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Build adjacency list
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);// track parents
        // remember or cache where we came from

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        typedef pair<int, int> pii; // {distance, node}
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, 1});
        dist[1] = 0;

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            for (auto [v, wt] : adjList[u])
            {
                if (d + wt < dist[v])
                {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }

        if (dist[n] == INT_MAX)
            return {-1};

        // Reconstruct path
        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        // Format as required: [distance, path...]
        // Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.
        vector<int> result;
        result.push_back(dist[n]);
        for (int x : path)
            result.push_back(x);

        return result;
    }
};
