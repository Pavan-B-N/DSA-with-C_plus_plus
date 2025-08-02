// https://leetcode.com/problems/subarrays-with-k-different-integers/
// SlidingWindow\BinarySubarrayWithSum.cpp
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
*/
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int a = subarraysWithAtMostKDistinct(nums, k);
        int b = subarraysWithAtMostKDistinct(nums, k - 1);
        return a - b;
    }
    ///<=k
    int subarraysWithAtMostKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap; //{ele,freq}
        int left = 0;
        int subArrays = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            freqMap[nums[right]]++;

            // Shrink window if too many distinct elements
            while (freqMap.size() > k)
            {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0)
                {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
            subArrays += (right - left + 1);
        }
        return subArrays;
    }
};