// https://leetcode.com/problems/partition-equal-subset-sum/
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (auto ele : nums)
        {
            totalSum += ele;
        }

        // if totalSum is odd then we cannot divide into two equal sum subsets
        if (totalSum % 2 != 0)
        {
            return false;
        }

        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetWithSumEqualsK(nums, n - 1, target, dp);
    }

    bool subsetWithSumEqualsK(vector<int> &nums, int i, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }

        if (i == 0)
        {
            return nums[i] == target;
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        // shrink the size of array everytime i-1
        bool notPick = subsetWithSumEqualsK(nums, i - 1, target, dp);
        bool pick = false;
        if (target > nums[i])
        {
            pick = subsetWithSumEqualsK(nums, i - 1, target - nums[i], dp);
        }

        return dp[i][target] = pick || notPick;
    }
};