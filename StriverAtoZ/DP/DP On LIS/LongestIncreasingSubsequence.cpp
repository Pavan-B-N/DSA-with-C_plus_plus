// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1), prev(n, -1);

        // Fill dp[] and prev[] arrays
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j; // store predecessor (not needed for length)
                }
            }
        }

        // Find max LIS length
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return LIS(0, -1, nums, dp);
    }

    int LIS(int index, int prevIndex, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index][prevIndex + 1] != -1)
        {
            return dp[index][prevIndex + 1];
        }

        // notPick4
        int notPick = 0 + LIS(index + 1, prevIndex, nums, dp);

        int pick = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            pick = 1 + LIS(index + 1, index, nums, dp);
        }

        return dp[index][prevIndex + 1] = max(pick, notPick);
    }

    // tabulation
    //  Tabulation just reverses the direction of computation, but computes the same values as recursion would, because it's filling the dp table in the order required to ensure subproblems are already computed when needed.
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[index][prev+1]

        for (int index = n - 1; index >= 0; index--)
        {
            // prevIndex =  n-1 to -1
            for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
            {
                int notPick = dp[index + 1][prevIndex + 1];

                int pick = 0;
                if (prevIndex == -1 || nums[index] > nums[prevIndex])
                {
                    pick = 1 + dp[index + 1][index + 1];
                }

                dp[index][prevIndex + 1] = max(pick, notPick);
            }
        }

        return dp[0][0]; // dp[0][-1+1]
    }
};