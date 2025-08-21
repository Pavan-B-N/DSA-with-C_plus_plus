#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// https://www.geeksforgeeks.org/problems/topological-sort/1

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v) {
        // directed graph
        adjacencyList[u].push_back(v);
    }

    void dfs(int currentVertex, vector<bool> &visited, stack<int> &s) {
        visited[currentVertex] = true;

        for (const auto &neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, s);
            }
        }

        s.push(currentVertex);
    }

    void topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> s;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i, visited, s);
            }
        }

        cout << "Topological Sort:" << endl;
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    // Add edges
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);


    g.topologicalSort();

    return 0;
}
