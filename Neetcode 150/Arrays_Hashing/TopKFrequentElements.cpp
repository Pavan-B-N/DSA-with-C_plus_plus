// https://leetcode.com/problems/top-k-frequent-elements/
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

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

        priority_queue<pair<int, int>> maxHeap; // freq,ele
        for (auto pair : freq)
        {
            auto [ele, count] = pair;
            maxHeap.push({count, ele});
        }

        vector<int> res;
        while (!maxHeap.empty() && k > 0)
        {
            int ele = maxHeap.top().second;
            maxHeap.pop();
            res.push_back(ele);
            k--;
        }

        if (k != 0)
        {
            return {-1, -1};
        }
        return res;
    }
};