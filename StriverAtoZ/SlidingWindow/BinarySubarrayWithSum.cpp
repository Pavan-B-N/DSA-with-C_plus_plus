// https://leetcode.com/problems/binary-subarrays-with-sum/
#include <vector>
using namespace std;
/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4

*/
class Solution
{
public:
    // count(sum==goal) = count(sum <= goal) - count(sum <= goal-1)
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int a = subArraysWithSumLessOrEquals(nums, goal);
        int b = subArraysWithSumLessOrEquals(nums, goal - 1);
        return a - b;
    }
    // count number of subarrays less than or eqauls to goal
    int subArraysWithSumLessOrEquals(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int left = 0;

        int subArrays = 0;
        long long sum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum > goal)
            {
                sum -= nums[left];
                left++;
            }
            subArrays += (right - left + 1);
        }
        return subArrays;
    }
};