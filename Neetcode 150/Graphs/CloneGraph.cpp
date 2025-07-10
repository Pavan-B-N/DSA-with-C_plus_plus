// https://leetcode.com/problems/clone-graph/


#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Time Complexity: O(V + E)
// Space Complexity	O(V)
// Cloned Graph (output)	O(V + E)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> cloneMap; // original -> cloned node
        queue<Node*> q;

        // Clone the starting node
        Node* cloneNode = new Node(node->val);
        cloneMap[node] = cloneNode;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    // Clone the neighbor if it hasn't been cloned yet
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Link the clone of the neighbor to the current clone node
                cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        return cloneNode;
    }
};


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};