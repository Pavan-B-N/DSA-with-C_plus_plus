#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    // o(logn)
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // o(1) for unorderd_map, o(logn) for map
        unordered_map<int, int> freq;
        for (auto num : nums)
        {
            freq[num]++;
        }

        // o(logn)
        priority_queue<pair<int, int>> pq; // max-heap {frequency, element}
        for (auto [num, count] : freq)
        {
            pq.push({count, num});
        }

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
