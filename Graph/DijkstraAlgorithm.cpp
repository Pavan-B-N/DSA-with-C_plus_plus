// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
/*
- Dijkstra's algorithm is a generalization of BFS to graphs with non-negative weighted edges. Unlike BFS, where every edge has equal weight, here weights can vary.

The key difference:

BFS uses a queue (FIFO), which processes nodes in the order they are discovered.

Dijkstra uses a priority queue (min-heap) to always pick the next closest vertex (the one with the smallest tentative distance) to process next.

This makes Dijkstra much faster and more efficient for weighted graphs compared to a naïve approach where you might have to scan all vertices repeatedly.

It avoids revisiting or processing nodes in the wrong order, which BFS can't do on weighted graphs.

For graphs with negative weights, algorithms like Bellman-Ford are used.

Dijkstra finds shortest paths from a single source to all other vertices.

It is not designed for all-pairs shortest path problems (where Floyd-Warshall is used).


*/
// Applications of Dijkstra's Algorithm
/*
GPS and Navigation systems:
Network Routing Protocols:

// Regular BFS vs PQ
/*
In unweighted graphs, all edges have the same "weight" (usually 1), so BFS naturally finds the shortest path because each step adds the same cost. Here, a simple FIFO queue suffices — no need for a priority queue.

In weighted graphs, edges can have different costs (weights), so just visiting nodes in the order they're discovered (like BFS) won't guarantee the shortest path.

Using a priority queue (min-heap) helps always pick the vertex with the smallest tentative distance next, which avoids unnecessary exploration of longer paths early on.

This reduces the overall number of relaxations and vertex revisits, leading to a more efficient algorithm compared to scanning all vertices every time.

*/

// Use BFS for unweighted graphs — it's simpler and faster.

// Use Dijkstra for weighted graphs with non-negative weights.

// Using adjacency lists and a binary heap, complexity is
// 𝑂 ( ( 𝑉 + 𝐸 ) log ⁡ 𝑉 )

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // build adjList
        vector<vector<pair<int, int>>> adjList(V); //{v,wt}
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        // min heap {distance,vertex}
        priority_queue<
            pair<int, int>,         // element ,{distance,vertex}
            vector<pair<int, int>>, // container
            greater<pair<int, int>> // comparison for min heap
            >
            pq;
        // "Whenever comparing two elements, the one with greater value should come after — so the smallest value bubbles to the top."

        pq.push({0, src});

        vector<int> dist(V, 1e9); // largest number
        dist[src] = 0;

        while (!pq.empty())
        {
            pair<int, int> topElement = pq.top();
            int distance = topElement.first;
            int u = topElement.second;

            pq.pop();
            for (auto neighbor : adjList[u])
            {
                int v = neighbor.first;
                int wt = neighbor.second;
                if (distance + wt < dist[v])
                {
                    dist[v] = distance + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == 1e9)
                dist[i] = 0;
        }

        return dist;
    }
};

// s.erase() takes a logn so it is not much efficient than pq
// // 𝑂 ( ( 𝑉 + 𝐸 ) log ⁡ 𝑉 )
class Solution1
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Build adjacency list: adjList[u] = vector of {v, weight}
        vector<vector<pair<int, int>>> adjList(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
        }

        // Set to act as a min-priority queue storing pairs {distance, vertex}
        set<pair<int, int>> st;
        st.insert({0, src});

        // Initialize distances with a large number
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        while (!st.empty())
        {
            auto topElement = *st.begin();
            int distance = topElement.first;
            int u = topElement.second;

            st.erase(st.begin());

            for (auto &neighbor : adjList[u])
            {
                int v = neighbor.first;
                int wt = neighbor.second;

                if (distance + wt < dist[v])
                {
                    // If v is already by someone then i know that it still present int the set and also we no need to process it if we found the much lesser node which can also reach the same
                    // so set gives a option to delete the already visited nodes where pq cannot
                    // Using a set gives you the ability to cleanly remove old distance entries, avoiding extra checks for outdated info during extraction. Priority queue can’t remove arbitrary elements, so you must handle stale entries by checks.
                    if (dist[v] != 1e9)
                        st.erase({dist[v], v}); // // Safe even if the pair is not in the set
                    dist[v] = distance + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        // Convert unreachable distances from 1e9 to 0 as per your original code
        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == 1e9)
                dist[i] = 0;
        }

        return dist;
    }
};
