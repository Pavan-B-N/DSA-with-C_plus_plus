/*

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/

/*
A node which is not a part of cycle or not connected to cycle is a safe node.
*/
// https://leetcode.com/problems/find-eventual-safe-states/
// FindEventualSafeStates.cpp

#include <iostream>
#include <vector>
using namespace std;

// industru required best code quality and readability but not exactly space optimized but we can suggest space optimized approach to interviewer
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &adjList)
    {
        int V = adjList.size();
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<bool> safeNodes(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjList, visited, pathVisited, safeNodes);
            }
        }

        vector<int> res;
        for (int i = 0; i < V; i++)
        {
            if (safeNodes[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }

    bool dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &pathVisited, vector<bool> &safeNodes)
    {
        visited[node] = true;
        pathVisited[node] = true;
        safeNodes[node] = false;

        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adjList, visited, pathVisited, safeNodes))
                    return true;
            }
            else if (pathVisited[neighbor])
            {
                return true;
            }
        }

        // visited[node] = true;
        pathVisited[node] = false;
        safeNodes[node] = true;
        return false;
    }
};
