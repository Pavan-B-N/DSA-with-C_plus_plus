// https://leetcode.com/problems/subarray-sum-equals-k/
#include <vector>
#include <unordered_map>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hashMap; // {prefixSum, count}
        int prefixSum = 0, subArrayCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            // If current prefix sum equals k, we found a subarray from index 0
            if (prefixSum == k)
            {
                subArrayCount++;
            }

            int remaining = prefixSum - k;
            if (hashMap.count(remaining))
            {
                subArrayCount += hashMap[remaining];
            }

            // Update the hash map
            hashMap[prefixSum]++;
        }

        return subArrayCount;
    }
};