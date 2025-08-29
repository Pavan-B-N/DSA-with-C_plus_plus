// https://leetcode.com/problems/jump-game/
#include <vector>
using namespace std;
/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
// optimal
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (reachable < i)
                return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

// DP = memoization
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1); // -1 means uncomputed, 0 = false, 1 = true
        return helper(0, nums, dp);
    }

    bool helper(int index, vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        if (index == n - 1)
            return true;
        if (dp[index] != -1)
            return dp[index];

        for (int i = 1; i <= nums[index] && index + i < n; i++)
        {
            if (helper(index + i, nums, dp))
            {
                return dp[index] = 1;
            }
        }

        return dp[index] = 0;
    }
};