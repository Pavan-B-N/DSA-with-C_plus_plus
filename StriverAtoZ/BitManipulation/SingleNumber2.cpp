// https://leetcode.com/problems/single-number-ii/
/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/
#include <vector>
#include <algorithm>
using namespace std;

// brute force
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        // T.C =  O(32 * n)
        for (int bitIndex = 0; bitIndex < 32; bitIndex++)
        {
            int countSetBits = 0;
            for (int ele : nums)
            {
                if (ele & 1 << bitIndex)
                {
                    countSetBits++;
                }
            }
            if (countSetBits % 3 == 1)
            {
                ans = ans | 1 << bitIndex;
            }
        }
        return ans;
    }
};

// better
class Solution
{
public:
    // nlogn
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 3)
        {
            if (nums[i] != nums[i - 1])
            {
                return nums[i - 1];
            }
        }
        return nums[n - 1];
    }
};