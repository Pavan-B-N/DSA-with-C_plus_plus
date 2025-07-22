// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// tag: [favorite]
/*
You are given a array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

1. Every consecutive pair of integers have opposite signs.
2. For all integers with the same sign, the order in which they were present in nums is preserved.
3. The rearranged array begins with a positive integer.

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
*/
#include <vector>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n, 0);
        int posIndex = 0;
        int negIndex = 1;

        for (int ele : nums)
        {
            if (ele >= 0)
            {
                ans[posIndex] = ele;
                posIndex += 2;
            }
            else
            {
                ans[negIndex] = ele;
                negIndex += 2;
            }
        }
        return ans;
    }
};