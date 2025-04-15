/*
https://leetcode.com/problems/find-the-duplicate-number/description/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }

    // cyclic sort but modify array
    int findDuplicate2(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Find the index corresponding to the value
            
            if (nums[index] < 0) {
                return abs(nums[i]);
            } else {
                // Mark as visited by negating
                nums[index] = -nums[index];
            }
        }
        
        return -1;
    }
};