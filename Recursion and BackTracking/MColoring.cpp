// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
// TIME COMPLEXITY = O(N^M)
    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adjList(v);
        vector<int> colors(v, -1);
        // BUILD ADJACENCY LIST
        for (auto edge : edges)
        {
            if (edge.size() <= 1)
            {
                continue;
            }
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return canColor(adjList, v, colors, 0, m);
    }

    bool canColor(vector<vector<int>> &adjList, int v, vector<int> &colors, int node, int m)
    {
        if (node == v)
        {
            return true;
        }
        for (int i = 0; i < m; i++)
        {
            if (isValidColor(adjList, colors, node, i))
            {
                colors[node] = i;
                if (canColor(adjList, v, colors, node + 1, m) == true)
                {
                    return true;
                }
                colors[node] = -1;
            }
        }

        return false;
    }

    bool isValidColor(vector<vector<int>> &adjList, vector<int> &colors, int node, int color)
    {
        for (auto neighbor : adjList[node])
        {
            if (colors[neighbor] == color)
            {
                return false;
            }
        }

        return true;
    }
};
