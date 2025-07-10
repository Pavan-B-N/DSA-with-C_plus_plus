// https://leetcode.com/problems/minimum-interval-to-include-each-query/
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        sort(intervals.begin(), intervals.end());

        // Store queries with their original indices
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i)
        {
            sortedQueries.push_back(make_pair(queries[i], i));
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-heap: pair of (interval size, interval end)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        vector<int> result(queries.size(), -1);
        int j = 0; // pointer for intervals

        for (int i = 0; i < sortedQueries.size(); ++i)
        {
            int query = sortedQueries[i].first;
            int index = sortedQueries[i].second;

            // Add intervals whose start <= query
            while (j < intervals.size() && intervals[j][0] <= query)
            {
                int start = intervals[j][0];
                int end = intervals[j][1];
                if (end >= query)
                {
                    int size = end - start + 1;
                    minHeap.push({size, end});
                }
                ++j;
            }

            // Remove intervals whose end < query
            while (!minHeap.empty() && minHeap.top().second < query)
            {
                minHeap.pop();
            }

            if (!minHeap.empty())
            {
                result[index] = minHeap.top().first; // Minimum interval size
            }
        }

        return result;
    }
};
