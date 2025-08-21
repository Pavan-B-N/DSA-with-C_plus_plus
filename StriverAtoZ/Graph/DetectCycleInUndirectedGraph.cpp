// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using bfs
bool detect(int src, vector<int> adjacencyList[], vector<bool> &visited)
{

    queue<pair<int, int>> q;// node, parent

    q.push({src, -1});
    visited[src] = true;

    while (!q.empty())
    {
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int adjacentNode : adjacencyList[curr])
        {
            if (!visited[adjacentNode])
            {
                q.push({adjacentNode, curr});
                visited[adjacentNode] = true;
            }
            else if (parent != adjacentNode)
            {
                // adjacent node is parent thats why its visited
                // if adjacent node is not a parent then there is no chance for visiting that node
                return true;
            }
        }
    }

    return false;
}

// O(V + E)
// Time Complexity: O(V + E)
// isCycle O(V)
// detect or bfs = O(V + E)
//  both BFS and DFS have a time complexity of: O(V + E)
// Adjacency List	✅ O(V + E)
// Adjacency Matrix	❌ O(V²)
// So avoid adjacency matrix unless you're forced to or the graph is dense.
bool isCycle(int V, vector<int> adjacencyList[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {   // connected components
        if (!visited[i] && detect(i, adjacencyList, visited))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3}};
    vector<int> adjacencyList[4];

    // create a adjacency list
    for (auto list : edges)
    {
        adjacencyList[list[0]].push_back(list[1]);
        adjacencyList[list[1]].push_back(list[0]);
    }


    cout << isCycle(4, adjacencyList) << endl;

    return 0;
}
