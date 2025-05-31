/// DetectCycleInDirectedGraph using BFS or togosort - kahn's algo
// toposort is only applicable for DAG 
// the intuition is that for cyclic graphs we know that toposort is not applicable so if we apply toposort to cyclic graph then we cannot produce a toposort with length V
// so if can conclude that if we cannot produce a toposort with length V then there is a cycle


// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
        
        return res.size()!=V; // this is just the diff between toposort and cycle detection
    }
    
  
};
