// https://leetcode.com/problems/network-delay-time/
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Dijkstra's Algorithm - Shortest Path from node k
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> distance(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adjList(n + 1); // u -> {v, weight}

        // Build the graph
        for (auto &edge : times)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
        }

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        distance[k] = 0;

        while (!pq.empty())
        {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            // Optimization: Skip if we already found a better path
            if (currDist > distance[currNode])
                continue;

            for (auto &[neighbor, weight] : adjList[currNode])
            {
                if (currDist + weight < distance[neighbor])
                {
                    distance[neighbor] = currDist + weight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        // Find the longest shortest-path time
        int maxTime = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (distance[i] == INT_MAX)
                return -1;
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};
