// Kahns Algorithm = BFS
// Topological sorting is a linear ordering of vertices such that if there is an edge {u,v} then u vertex should appear before vertex v in order.
// Topological sorting is valid only in DAG
// Directed Acyclic Graph

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// https://www.geeksforgeeks.org/problems/topological-sort/1

// Algo
/*
* Initially find indegree of the vertices
* push the vertices with indegree with 0 to queue
* remove element or vertex from queue so indegree of neighbors decreases by 1
* the vertices with indegree are included in the queue and are part of toposort in a linear order
*/
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(V);

        // build adjList
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }

        queue<int> q;
        vector<int> indegree(V, 0);
        // adjList
        // 0 = {1,2}
        // 1 = {2,1}
        // calculate indegrees
        for (auto vec : adjList)
        {
            for (auto neighbor : vec)
                indegree[neighbor]++;
        }

        // check for the nodes which has 0 as their indegree
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            res.push_back(ele);

            for (auto neighbor : adjList[ele])
            {
                // node is in toposort, so remove the element from a graph
                // removing the element caused remove in the indegress of the neighbors 
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        return res;
    }
};
