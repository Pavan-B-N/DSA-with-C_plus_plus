// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
/*
Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6
*/
#include <vector>
#include <unordered_map>
using namespace std;
// tag: [favorite]

// Time Complexity: O(n * 1)
// Time Complexity bloom Moon: O(n*n) due to collision
// Space Complexity: O(n) due to hashMap

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        unordered_map<int, int> hashMap; //{prefixSum,index}
        int prefixSum = 0;
        int maxLen = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            prefixSum += arr[i];
            if (prefixSum == k)
            {
                maxLen = max(maxLen, i + 1);
            }
            int remaining = prefixSum - k;
            if (hashMap.count(remaining))
            {
                int len = i - hashMap[remaining];
                maxLen = max(maxLen, len);
            }
            // because neg or 0, can decrease or keep the sum same, so to find longest subarray we have to staty at same place
            if (hashMap.find(prefixSum) == hashMap.end())
                hashMap[prefixSum] = i;
        }
        return maxLen;
    }
};

// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM
// 0 <= 'a[i]' <= 10 ^ 9
// only positive numbers
// Time complexity: O(n)
int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    int left = 0;
    int maxLen = 0;
    long long prefixSum = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        prefixSum += arr[right];

        // Shrink the window from the left while prefixSum is greater than k
        while (left <= right && prefixSum > k)
        {
            prefixSum -= arr[left++];
        }

        if (prefixSum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

// Brute Force: TLE
// Time complexity: O(n^2)
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int maxLen = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            for (int j = i; j < n; j++)
            {
                currSum += arr[j];
                if (currSum == k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};