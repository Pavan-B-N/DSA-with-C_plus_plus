// https://leetcode.com/problems/course-schedule/

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        for (auto edge : prerequisites)
        {
            int u = edge[1];
            int v = edge[0];
            adjList[u].push_back(v);
        }

        // apply topological sort using kahns algo bfs
        vector<int> indegree(numCourses, 0);
        for (auto neighbors : adjList)
        {
            for (auto neighbor : neighbors)
            {
                indegree[neighbor]++;
            }
        }
        // push vertices with 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for (auto neighbor : adjList[curr])
            {
                // we are removing parent node because its part of topo
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return topo.size() == numCourses;
    }
};