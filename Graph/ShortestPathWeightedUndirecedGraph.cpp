// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Step 1: Create an adjacency list to represent the graph
        // Each entry adj[u] contains pairs {v, weight}, representing an edge u -> v with weight
        vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt}); // Undirected graph: add both u->v and v->u
            adj[v].push_back({u, wt});
        }

        // Step 2: Initialize distance and parent arrays
        vector<int> dist(n + 1, INT_MAX); // Distance from source to each node
        vector<int> parent(n + 1);        // To reconstruct the path

        // Initially, set each node's parent to itself
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Step 3: Priority queue for Dijkstra's algorithm
        // Min-heap based on distance: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from source node (1)
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Visit all neighbors of current node
            for (auto neighbor : adj[u])
            {
                int v = neighbor.first;
                int wt = neighbor.second;

                // If a shorter path to v is found
                if (d + wt < dist[v])
                {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                    parent[v] = u; // Track the parent for path reconstruction
                }
            }
        }

        // Step 4: If destination node 'n' is unreachable, return -1
        if (dist[n] == INT_MAX)
            return {-1};

        // Step 5: Reconstruct the shortest path from node 1 to node n
        vector<int> path;
        int node = n;

        // Follow the parent chain backwards from destination to source
        while (node != 1)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); // Add the source node

        // Since we built the path from destination to source, reverse it
        reverse(path.begin(), path.end());
        return path;
    }

    int main()
    {
        // Example static data: n = 5, m = 6
        int n = 5, m = 6;
        vector<vector<int>> edges = {
            {1, 2, 2},
            {1, 3, 4},
            {2, 3, 1},
            {2, 4, 7},
            {3, 5, 3},
            {4, 5, 1}
        };

        Solution sol;
        vector<int> path = sol.shortestPath(n, m, edges);

        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
        return 0;
    }
};