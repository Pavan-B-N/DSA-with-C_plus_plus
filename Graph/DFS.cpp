#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        // Uncomment the following line for an undirected graph
        adjacencyList[v].push_back(u);
    }

    // recommended one
    void dfsRecursive(int currentVertex, vector<bool> &visited)
    {
        visited[currentVertex] = true;
        cout << currentVertex << " ";

        for (const auto &neighbor : adjacencyList[currentVertex])
        {
            if (!visited[neighbor])
            {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    void dfs(int startVertex)
    {
        vector<bool> visited(vertices, false);
        dfsRecursive(startVertex, visited);
    }

    // use recursive method
    void dfsUsingStack(int startVertex)
    {
        vector<bool> visited(vertices, false);
        stack<int> s;

        visited[startVertex] = true; // Mark as visited when pushing
        s.push(startVertex);

        while (!s.empty())
        {
            int currentVertex = s.top();
            s.pop();

            cout << currentVertex << " ";

            for (const auto &neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true; // Mark as visited when pushing
                    s.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    Graph g(5); // Create a graph with 6 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    cout << "DFS starting from vertex 0:" << endl;
    g.dfs(0);

    return 0;
}
