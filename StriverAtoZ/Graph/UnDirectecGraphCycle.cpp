// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(V);
        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (bfs(i, adjList, visited))
                    return true;
            }
        }

        return false;
    }

    bool bfs(int start, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        queue<pair<int, int>> q; // node, parent
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty())
        {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adjList[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push({neighbor, curr});
                }
                else if (neighbor != parent)
                {
                    return true; // Cycle detected
                }
            }
        }
        return false;
    }
};