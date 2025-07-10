// https://leetcode.com/problems/coin-change/
#include <vector>
#include <string>
using namespace std;

// memo
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }

    int helper(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        // Not pick
        int notPick = helper(index - 1, amount, coins, dp);

        // Pick
        int pick = 1e9;
        if (amount >= coins[index])
            pick = 1 + helper(index, amount - coins[index], coins, dp);

        return dp[index][amount] = min(pick, notPick);
    }
};

// tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        if (n < 1)
        {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int currAmount = 0; currAmount <= amount; currAmount++)
            {
                int notPick = dp[index - 1][currAmount];
                int pick = 1e9;
                if (coins[index] <= currAmount)
                {
                    pick = 1 + dp[index][currAmount - coins[index]];
                }

                dp[index][currAmount] = min(pick, notPick);
            }
        }

        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};
