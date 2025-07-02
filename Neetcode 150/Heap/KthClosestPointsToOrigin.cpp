// https://leetcode.com/problems/k-closest-points-to-origin/
#include <queue>
#include <vector>
using namespace std;

// most optimal
// time complexity: O(n log k)
// space complexity: O(k)
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;

        if (k > points.size() || points.size() < 1)
        {
            return ans;
        }
        // Min-heap with pair: (distance, point)
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto &point : points)
        {
            int dist = point[0] * point[0] + point[1] * point[1];
            if (maxHeap.size() < k)
            {
                maxHeap.push({dist, point});
            }
            else if (dist <= maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push({dist, point});
            }
        }

        while (k > 0 && !maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }

        return ans;
    }
};

// time complexity: O(n log n)
// space complexity: O(n)
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;

        if (k > points.size() || points.size() < 1)
        {
            return ans;
        }
        // Min-heap with pair: (distance, point)
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                       greater<>>
            minHeap;

        for (const auto &point : points)
        {
            int dist = point[0] * point[0] + point[1] * point[1];
            minHeap.push({dist, point});
        }

        while (k > 0 && !minHeap.empty())
        {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }

        return ans;
    }
};
