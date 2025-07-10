// https://leetcode.com/problems/house-robber/description/
#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxSumOfNonAdjacentElements(n - 1, nums, dp);
    }
    int maxSumOfNonAdjacentElements(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index < 0)
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int notPick = 0 + maxSumOfNonAdjacentElements(index - 1, nums, dp);
        int pick = nums[index] + maxSumOfNonAdjacentElements(index - 2, nums, dp);

        return dp[index] = max(notPick, pick);
    }
};

// tabulation
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int notPick = 0 + dp[i - 1];
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};

// tabulation optimized
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int notPick = 0 + prev1;
            int pick = nums[i] + prev2;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};