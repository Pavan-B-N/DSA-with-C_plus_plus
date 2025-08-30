// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <iostream>
#include <vector>
using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // buy = 0,1
        // maxTransactions = [0 - 2]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return getMaxProfit(0, 1, 2, prices, dp);
    }

    // You may complete at most two transactions.
    int getMaxProfit(int index, int buy, int maxTransactions,
                     vector<int> &prices, vector<vector<vector<int>>> &dp)
    {

        if (maxTransactions == 0)
            return 0;
        if (index == prices.size())
            return 0;

        if (dp[index][buy][maxTransactions] != -1)
            return dp[index][buy][maxTransactions];

        int profit;
        if (buy)
        {
            // Option to buy or skip
            int buyNow =
                -prices[index] +
                getMaxProfit(index + 1, 0, maxTransactions, prices, dp);
            int skipBuy =
                getMaxProfit(index + 1, 1, maxTransactions, prices, dp);
            profit = max(buyNow, skipBuy);
        }
        else
        {
            // Option to sell or skip
            int sellNow =
                prices[index] +
                getMaxProfit(index + 1, 1, maxTransactions - 1, prices, dp);
            int skipSell =
                getMaxProfit(index + 1, 0, maxTransactions, prices, dp);
            profit = max(sellNow, skipSell);
        }

        dp[index][buy][maxTransactions] = profit;
        return profit;
    }
};

/*
Steps to convert memo to tabulation
- Identify base cases
- write a loops in reverse order
- copy recurrrance
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // dp[index][buy][transactionsLeft]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base case: dp[n][buy][t] = 0 already set (when index == n)
        // Base case: dp[i][buy][0] = 0 already set (when no transactions left)

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int t = 1; t <= 2; t++)
                {
                    if (buy)
                    {
                        int buyNow = -prices[index] + dp[index + 1][0][t];
                        int skipBuy = dp[index + 1][1][t];
                        dp[index][buy][t] = max(buyNow, skipBuy);
                    }
                    else
                    {
                        int sellNow = prices[index] + dp[index + 1][1][t - 1];
                        int skipSell = dp[index + 1][0][t];
                        dp[index][buy][t] = max(sellNow, skipSell);
                    }
                }
            }
        }

        return dp[0][1][2]; // start from day 0, can buy, 2 transactions left
    }
};
