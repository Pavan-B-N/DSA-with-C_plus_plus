// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // dp[index][buy][maxTransactions]
        // maxTransactions = [0,1,2,...k]
        // buy= [0,1]
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return getMaxProfit(0, 1, k, prices, dp);
    }
    int getMaxProfit(int index, int buy, int maxTransactions, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (maxTransactions == 0 || index == prices.size())
        {
            return 0;
        }
        if (dp[index][buy][maxTransactions] != -1)
            return dp[index][buy][maxTransactions];
        int profit;
        if (buy)
        {
            int buyNow = -prices[index] + getMaxProfit(index + 1, 0, maxTransactions, prices, dp);
            int dontBuyNow = getMaxProfit(index + 1, 1, maxTransactions, prices, dp);
            profit = max(buyNow, dontBuyNow);
        }
        else
        {
            int sellNow = prices[index] + getMaxProfit(index + 1, 1, maxTransactions - 1, prices, dp);
            int dontSellNow = getMaxProfit(index + 1, 0, maxTransactions, prices, dp);
            profit = max(sellNow, dontSellNow);
        }
        return dp[index][buy][maxTransactions] = profit;
    }
};

// tabulation
/*
Steps to convert to tabulation
- satisfy base cases
- write changining parameters (loops) in opposite or reverse order
- copy recurrrence
- return endPoints of loops
*/
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // dp[index][buy][maxTransactions]
        // maxTransactions = [0,1,2,...k]
        // buy= [0,1]
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int t = 1; t <= k; t++)
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

        return dp[0][1][k];
    }
};