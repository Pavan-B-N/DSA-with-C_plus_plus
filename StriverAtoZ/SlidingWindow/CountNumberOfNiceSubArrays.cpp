// https://leetcode.com/problems/count-number-of-nice-subarrays//
// SlidingWindow\BinarySubarrayWithSum.cpp
#include <vector>
using namespace std;
/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.


Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

class Solution
{
public:
    // A continuous subarray is called nice if there are k odd numbers on it.
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int a = countSubArrays(nums, k);
        int b = countSubArrays(nums, k - 1);
        return a - b;
    }

    // count the subarrays with <= k odd numbers
    int countSubArrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int subArrays = 0;
        int oddCount = 0;
        
        for (int right = 0; right < n; right++)
        {
            if (nums[right] % 2 == 1)
            {
                oddCount++;
            }

            while (oddCount > k)
            {
                if (nums[left] % 2 == 1)
                    oddCount--;
                left++;
            }

            subArrays += (right - left + 1);
        }
        return subArrays;
    }
};