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

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Auxiliary Space: O(V)
// Time complexity: o(V)
int numProvinces(vector<vector<int>> adj,const int V)
{
    // convert adjacency Matrix into adjacency list
    vector<int> adjLs[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    int provinces = 0;

    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfs(i, adjLs, visited);
            provinces++;
        }
    }

    return provinces;
}

// we can use any graph traversal algorithms
void bfs(int startIndex, vector<int> adj[], vector<bool> &visited)
{
    queue<int> q;
    q.push(startIndex);
    visited[startIndex] = true;

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();

        for (auto &neighbor : adj[cv])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}