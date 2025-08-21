// SafeNodes.cpp
// using Topological Sorting, we can reverse the graph and perform Kahn's Algorithm (BFS for topological sort).
// ✅ Why Reverse the Graph?
// In the original graph, a node is safe if all paths from it lead to terminal nodes.

// So, we reverse the graph and start from terminal nodes, and perform topological sort to find all nodes that can reach terminals.
// https://leetcode.com/problems/find-eventual-safe-states/
// tag: [revise]
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);

        // Step 1: Reverse the graph and compute in-degrees
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);  // reverse edge: v -> u
                inDegree[u]++;                 // count how many outgoing edges u has
            }
        }

        // Step 2: Initialize queue with nodes having 0 in-degree (i.e., terminal nodes in original graph)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Run BFS (Kahn’s algorithm)
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : reverseGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Collect all safe nodes
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
