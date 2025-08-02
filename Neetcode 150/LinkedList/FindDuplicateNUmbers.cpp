// https://leetcode.com/problems/find-the-duplicate-number/
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
/*
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 3:

Input: nums = [3,3,3,3,3]
Output: 3   


You must solve the problem without modifying the array nums and using only constant extra space.
so we cannot apply cyclic sort here due to constratins
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        // detect cycle
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // find start of cycle
        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};