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


// O(n^2) in the worst case.
// For each index i, you're potentially making up to nums[i] recursive calls.
// In the worst case (e.g., nums = {n, n-1, ..., 1}), you may go from i → i+1 → i+2 → ... → n-1.
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> dp(n, -1); // dp[i] = min jumps from i to end
        return (int)jumpFrom(0, nums, dp);
    }

    long long jumpFrom(int index, vector<int> &nums, vector<long long> &dp)
    {
        if (index == nums.size() - 1)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        long long minSteps = INT_MAX;
        for (int i = 1; i <= nums[index] && index + i < nums.size(); i++)
        {
            long long steps = 1 + jumpFrom(index + i, nums, dp);
            minSteps = min(minSteps, steps);
        }

        return dp[index] = minSteps;
    }
};
