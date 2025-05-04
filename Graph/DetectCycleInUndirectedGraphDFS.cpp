// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool dfs(int node, int parent, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        visited[node] = true;

        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, node, adjList, visited))
                {
                    return true;
                }
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }

        return false; // This line is important and was missing
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(V);
        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]); // Undirected graph
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adjList, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
