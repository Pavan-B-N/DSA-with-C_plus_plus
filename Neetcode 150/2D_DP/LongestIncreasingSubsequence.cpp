
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
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return LIS(0, -1, nums, dp);
    }
    int LIS(int index, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index][prev + 1] != -1)
        {
            return dp[index][prev + 1];
        }

        // notPick4
        int notPick = 0 + LIS(index + 1, prev, nums, dp);

        int pick = 0;
        if (prev == -1 || nums[index] > nums[prev])
        {
            pick = 1 + LIS(index + 1, index, nums, dp);
        }

        return dp[index][prev + 1] = max(pick, notPick);
    }

    // tabulation
    //  Tabulation just reverses the direction of computation, but computes the same values as recursion would, because it's filling the dp table in the order required to ensure subproblems are already computed when needed.
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[index][prev+1]

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int notPick = dp[index + 1][prev + 1];

                int pick = 0;
                if (prev == -1 || nums[index] > nums[prev])
                {
                    pick = 1 + dp[index + 1][index + 1];
                }

                dp[index][prev + 1] = max(pick, notPick);
            }
        }

        return dp[0][0]; // dp[0][-1+1]
    }
};