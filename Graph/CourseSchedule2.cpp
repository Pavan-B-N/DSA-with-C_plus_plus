// https://leetcode.com/problems/course-schedule-ii/description/
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// based on kahn's algorithm = bfs topological sorting

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // courses = 0 to numCourses-1
        // prerequisites are like edges
        // build adjList
        vector<vector<int>> adjList(numCourses);
        for (auto edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adjList[v].push_back(u);
        }

        // apply topological sort using kahns algo bfs
        vector<int> indegree(numCourses);
        for (auto vec : adjList) {
            for (auto neighbor : vec) {
                indegree[neighbor]++;
            }
        }

        // push vertices with 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            topo.push_back(vertex);

            for (auto neighbor : adjList[vertex]) {
                // we are removing parent node because its part of topo
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return topo.size() == numCourses ? topo : vector<int>();
    }
};