// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
*/
#include <iostream>
#include <vector>
using namespace std;

// memoization
// memoization
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // dp[index][buy] = max profit from day index with buy status
        // buy = [0,1];// 1 means allowed to buy
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getMaxProfit(0, 1, prices, dp); // buy = 1 means we can buy
    }

    int getMaxProfit(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit;
        // allowed or liberty to buy
        if (buy)
        {
            // Option to buy or skip
            int buyNow = -prices[index] + getMaxProfit(index + 1, 0, prices, dp);
            int dontBuyNow = getMaxProfit(index + 1, 1, prices, dp);
            profit = max(buyNow, dontBuyNow);
        }
        else
        {
            // Option to sell or skip
            int sellNow = prices[index] + getMaxProfit(index + 2, 1, prices, dp);
            int dontSellNow = getMaxProfit(index + 1, 0, prices, dp);
            profit = max(sellNow, dontSellNow);
        }

        return dp[index][buy] = profit;
    }
};

// memoication extra work
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // dp[index][buy][cooldown]
        // index = 0 to n
        // but = [0,1]
        // cooldown = [0,1]
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

        return getMaxProfit(0, 1, 0, prices, dp);
    }
    int getMaxProfit(int index, int buy, int cooldown, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
            return 0;
        if (dp[index][buy][cooldown] != -1)
            return dp[index][buy][cooldown];

        if (cooldown)
        {
            return dp[index][buy][cooldown] = getMaxProfit(index + 1, 1, 0, prices, dp);
        }

        int profit;
        // allowed or liberty to buy
        if (buy)
        {
            // Option to buy or skip
            int buyNow = -prices[index] + getMaxProfit(index + 1, 0, 0, prices, dp);
            int dontBuyNow = getMaxProfit(index + 1, 1, 0, prices, dp);
            profit = max(buyNow, dontBuyNow);
        }
        else
        {
            // Option to sell or skip
            int sellNow = prices[index] + getMaxProfit(index + 1, 1, 1, prices, dp);
            int dontSellNow = getMaxProfit(index + 1, 0, 0, prices, dp);
            profit = max(sellNow, dontSellNow);
        }

        return dp[index][buy][cooldown] = profit;
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // dp[index][buy][cooldown]
        // index = 0 to n
        // but = [0,1]
        // cooldown = [0,1]
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(2, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cooldown = 1; cooldown >= 0; cooldown--)
                {
                    if (cooldown)
                    {
                        dp[index][buy][cooldown] = dp[index + 1][1][0];
                        continue;
                    }

                    int profit;
                    // allowed or liberty to buy
                    if (buy)
                    {
                        // Option to buy or skip
                        int buyNow = -prices[index] + dp[index + 1][0][0];
                        //  getMaxProfit(index + 1, 0, 0, prices, dp);
                        int dontBuyNow = dp[index + 1][1][0];
                        // getMaxProfit(index + 1, 1, 0, prices, dp);
                        profit = max(buyNow, dontBuyNow);
                    }
                    else
                    {
                        // Option to sell or skip
                        int sellNow = prices[index] + dp[index + 1][1][1];
                        //   getMaxProfit(index + 1, 1, 1, prices, dp);
                        int dontSellNow = dp[index + 1][0][0];
                        // getMaxProfit(index + 1, 0, 0, prices, dp);
                        profit = max(sellNow, dontSellNow);
                    }

                    dp[index][buy][cooldown] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};