// https://leetcode.com/problems/subarray-sum-equals-k/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int count = 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        unordered_map<int, int> map; // prefixSum, frequency
        for (int j = 0; j < n; j++)
        {
            if (prefixSum[j] == k)
            {
                count++;
            }
            int val = prefixSum[j] - k;
            if (map.find(val) != map.end())
            {
                count += map[val];
            }

            map[prefixSum[j]]++;
        }
        return count;
    }
};