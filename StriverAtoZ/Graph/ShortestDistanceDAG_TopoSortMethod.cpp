// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Algorithm:-
// Step 1: Topological Sort
// Step 2: Initialize distances
// Step 3: Relaxation using topological order
// Step 4: Replace INT_MAX with -1 for unreachable vertices

// Time Complexity : O(V+E)
// Space Complexity : O(V + E), due to building adjList
class Solution
{
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // Build adjacency list
        vector<vector<pair<int, int>>> adjList(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
        }

        // Step 1: Topological Sort
        stack<int> topoStack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])// connected components
            {
                dfs(i, visited, adjList, topoStack);
            }
        }

        // Step 2: Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Source vertex

        // Step 3: Relaxation using topological order
        while (!topoStack.empty())
        {
            int u = topoStack.top();
            topoStack.pop();

            if (dist[u] != INT_MAX)
            {
                for (auto &neighbor : adjList[u])
                {
                    int v = neighbor.first;
                    int wt = neighbor.second;
                    if (dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 4: Replace INT_MAX with -1 for unreachable vertices
        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
    // topological sorting dfs
    // Time: O(V + E)
    // Space: O(V)
    void dfs(int vertex, vector<bool> &visited, vector<vector<pair<int, int>>> &adjList, stack<int> &s)
    {
        visited[vertex] = true;
        for (auto neighbor : adjList[vertex])
        {
            int v = neighbor.first;
            if (!visited[v])
            {
                dfs(v, visited, adjList, s);
            }
        }
        s.push(vertex);
    }
};
