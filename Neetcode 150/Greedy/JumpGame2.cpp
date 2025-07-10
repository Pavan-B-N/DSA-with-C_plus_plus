// https://leetcode.com/problems/jump-game-ii/
#include <vector>
using namespace std;
// O(n)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0;
        int farthest = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd)
            {
                jumps++;
                currentEnd = farthest;

                // Optional early exit
                if (currentEnd >= n - 1)
                    break;
            }
        }

        return jumps;
    }
};

// Good but gives TLE
// O(n^2)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // dp[index][steps]
        return jump(0, nums, 0, dp);
    }

    int jump(int index, vector<int> &nums, int steps, vector<vector<int>> &dp)
    {
        if (index >= nums.size() - 1)
        {
            return steps;
        }

        if (dp[index][steps] != -1)
            return dp[index][steps];

        int minSteps = INT_MAX;

        // O(n)
        for (int i = 1; i <= nums[index]; i++)
        {
            int totalSteps = jump(index + i, nums, steps + 1, dp);
            minSteps = min(minSteps, totalSteps);
        }

        return dp[index][steps] = minSteps;
    }
};
