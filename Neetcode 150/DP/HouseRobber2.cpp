// https://leetcode.com/problems/house-robber-ii/
#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Case 1: Rob from index 0 to n-2 (exclude last house)
        int case1 = robRecursive(n - 2, 0, nums, dp1);

        // Case 2: Rob from index 1 to n-1 (exclude first house)
        int case2 = robRecursive(n - 1, 1, nums, dp2);

        return max(case1, case2);
    }

private:
    // maxSumOfNonAdjacentElements
    int robRecursive(int index, int start, vector<int> &nums, vector<int> &dp)
    {
        if (index < start)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + robRecursive(index - 2, start, nums, dp);
        int notPick = robRecursive(index - 1, start, nums, dp);

        return dp[index] = max(pick, notPick);
    }
};

// tabulation
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // Case 1: Rob from index 0 to n-2 (exclude last house)
        int case1 = maxSumOfNonAdjacentElements(0, n - 2, nums);

        // Case 2: Rob from index 1 to n-1 (exclude first house)
        int case2 = maxSumOfNonAdjacentElements(1, n - 1, nums);

        return max(case1, case2);
    }
    int maxSumOfNonAdjacentElements(int start, int end, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[start] = nums[start];

        for (int i = start + 1; i <= end; i++)
        {
            int notPick = 0 + dp[i - 1];
            int pick = nums[i];
            if (i > start + 1)
            {
                pick += dp[i - 2];
            }
            dp[i] = max(pick, notPick);
        }
        return dp[end];
    }
};

// optimized tabulation solution
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // Case 1: Rob from index 0 to n-2 (exclude last house)
        int case1 = maxSumOfNonAdjacentElements(0, n - 2, nums);

        // Case 2: Rob from index 1 to n-1 (exclude first house)
        int case2 = maxSumOfNonAdjacentElements(1, n - 1, nums);

        return max(case1, case2);
    }
    int maxSumOfNonAdjacentElements(int start, int end, vector<int> &nums)
    {
        int prev1 = nums[start];
        int prev2 = 0;
        for (int i = start + 1; i <= end; i++)
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