// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
- Dijkstra's algorithm is a generalization of BFS to graphs with non-negative weighted edges.

The key difference:

BFS uses a queue (FIFO), which processes nodes in the order they are discovered.

Dijkstra uses a priority queue (min-heap) to always pick the next closest vertex
This makes Dijkstra much faster and more efficient for weighted graphs

For graphs with negative weights, algorithms like Bellman-Ford are used.

Dijkstra finds shortest paths from a single source to all other vertices.

It is not designed for all-pairs shortest path problems (where Floyd-Warshall is used).
*/

// Applications of Dijkstra's Algorithm
/*
GPS and Navigation systems:
Network Routing Protocols:
*/

// Use BFS for unit weighted graphs — it's simpler and faster.
// Use Dijkstra for weighted graphs with non-negative weights.

// Using binary heap, complexity is
// 𝑂 ( ( 𝑉 + 𝐸 ) log ⁡ 𝑉 )

// Non - negative , undirected
// User Function Template
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // build graph
        vector<vector<pair<int, int>>> adjList(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        typedef pair<int, int> pii; //{distance,node}
        priority_queue<pii, vector<pii>, greater<pii>> pq;// minHeap

        pq.push({0, src});

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] != INT_MAX)
            {
                for (auto [v, wt] : adjList[u])
                {
                    if (dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};