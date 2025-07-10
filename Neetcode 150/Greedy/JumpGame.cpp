// https://leetcode.com/problems/jump-game/
#include <vector>
#include <iostream>
using namespace std;

// greedy
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > reachable)
                return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

// dp memo
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
