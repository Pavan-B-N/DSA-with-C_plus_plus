// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // You can either start from the step with index 0, or 1.
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }

    int helper(int index, vector<int> &cost, vector<int> &dp)
    {
        int n = cost.size();
        if (index == n)
            return 0; // reached the top floor
        if (index > n)
            return INT_MAX; // invalid step

        if (dp[index] != -1)
            return dp[index];

        int step1 = helper(index + 1, cost, dp);
        int step2 = helper(index + 2, cost, dp);
        return dp[index] = cost[index] + min(step1, step2);
    }
};


// tabulation
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1); // dp[i] = min cost to reach step i

        // Base cases:
        dp[0] = 0; // Start before step 0
        dp[1] = 0; // Or start before step 1

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1],  // one step
                        dp[i - 2] + cost[i - 2]); // two steps
        }

        return dp[n]; // Minimum cost to reach the "top"
    }
};