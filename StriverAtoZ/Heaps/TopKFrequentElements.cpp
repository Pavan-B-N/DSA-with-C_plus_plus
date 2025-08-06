// https://leetcode.com/problems/top-k-frequent-elements/
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Let n = total input size, m = number of distinct elements (m ≤ n).
// Time Complexity: O(3n + mlogk) = O(n + m log k) = O(n + n log k)
// Space complexity: O(n+k) = O(n)
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq; // ele,freq
        for (int ele : nums)
        {
            freq[ele]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; //{freq,ele}

        for (auto &it : freq)
        {
            auto [ele, freq] = it;
            if (minHeap.size() < k)
            {
                minHeap.push({freq, ele});
            }
            else if (freq > minHeap.top().first)
            {
                minHeap.pop();
                minHeap.push({freq, ele});
            }
        }

        vector<int> res;
        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
