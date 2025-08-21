// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(V);
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dfs(i, adjList, visited, pathVisited))
            {
                return true;
            }
        }

        return false;
    }

    bool dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &pathVisited)
    {
        visited[node] = true;
        pathVisited[node] = true;

        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adjList, visited, pathVisited))
                    return true;
            }
            else if (pathVisited[neighbor])
            {
                return true;
            }
        }

        pathVisited[node] = false;
        return false;
    }
};