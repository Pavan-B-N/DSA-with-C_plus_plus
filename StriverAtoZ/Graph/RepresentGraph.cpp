#include <iostream>
#include <vector>

using namespace std;
// graph is designed for undirected graph
class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // comment this line for an directed graph
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << " is connected to:";
            for (const auto &neighbor : adjacencyList[i]) {
                cout << " " << neighbor;
            }
            cout << endl;
        }
    }
};

class GraphUsingAdjacencyMatrix {
public:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

    GraphUsingAdjacencyMatrix(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // comment this line for an directed graph
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    Graph g(5); // Create a graph with 5 vertices
    // GraphUsingAdjacencyMatrix g(5); // Create a graph with 5 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}
