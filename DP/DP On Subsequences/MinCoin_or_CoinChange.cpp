// https://leetcode.com/problems/coin-change/
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0

*/
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = countMinCoins(n - 1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }

    int countMinCoins(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        int notPick = 0 + countMinCoins(index - 1, coins, amount, dp);
        int pick = 1e9; // we can also use INT_MAX but adding 1 to it causes integer overflow
        if (coins[index] <= amount)
        {
            pick = 1 + countMinCoins(index, coins, amount - coins[index], dp);
        }

        return dp[index][amount] = min(pick, notPick);
    }
};

// tabulation
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