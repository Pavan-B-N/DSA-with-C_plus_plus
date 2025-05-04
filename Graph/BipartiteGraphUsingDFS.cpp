// https://www.geeksforgeeks.org/problems/bipartite-graph/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<vector<int>> adjList(V);
        vector<int> color(V, -1);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(adjList, color, i, 0) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>> &adjList, vector<int> &color, int node, int colorOfNode)
    {
        color[node] = colorOfNode;

        for (auto neighbor : adjList[node])
        {
            if (color[neighbor] == -1)
            {
                dfs(adjList, color, neighbor, !colorOfNode);
            }
            else if (color[neighbor] == color[node])
            {
                return false;
            }
        }
        return true;
    }
};
