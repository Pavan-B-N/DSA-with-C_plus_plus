/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

https://www.geeksforgeeks.org/problems/number-of-provinces/1

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

*/

// https://leetcode.com/problems/number-of-provinces/description/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Auxiliary Space: O(V)
// Time complexity: o(V + E)
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &adjMatrix)
    {
        int provinces = 0;
        int V = adjMatrix.size();

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfs(i, adjMatrix, visited);
                provinces++;
            }
        }

        return provinces;
    }
    void bfs(int startIndex, vector<vector<int>> &adjMatrix,
             vector<bool> &visited)
    {
        int V = adjMatrix.size();
        queue<int> q;
        q.push(startIndex);
        visited[startIndex] = true;

        while (!q.empty())
        {
            int cv = q.front();
            q.pop();

            for (int i = 0; i < V; i++)
            {
                if (adjMatrix[cv][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};