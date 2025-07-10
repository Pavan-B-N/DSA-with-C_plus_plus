// https://leetcode.com/problems/coin-change-ii/description/

#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return findWays(n - 1, amount, coins, dp);
    }

    int findWays(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }

        int notPick = findWays(index - 1, amount, coins, dp);
        int pick = 0;
        if (amount >= coins[index])
        {
            pick = findWays(index, amount - coins[index], coins, dp);
        }

        return dp[index][amount] = pick + notPick;
    }
};

// tabulation
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            if (currAmount % coins[0] == 0)
                dp[0][currAmount] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            for (int currAmount = 0; currAmount <= amount; currAmount++)
            {
                unsigned long long notPick = dp[index - 1][currAmount];
                unsigned long long pick = 0;
                if (currAmount >= coins[index])
                {
                    pick = dp[index][currAmount - coins[index]];
                }
                dp[index][currAmount] = pick + notPick;
            }
        }

        return static_cast<int>(dp[n - 1][amount]);
    }
};