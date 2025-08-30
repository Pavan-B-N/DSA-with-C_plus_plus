// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // dp[index][buy] = max profit from day index with buy status
        // buy = [0,1];// 1 means allowed to buy
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getMaxProfit(0, 1, prices, dp, fee); // buy = 1 means we can buy
    }
    int getMaxProfit(int index, int buy, vector<int> &prices, vector<vector<int>> &dp, int fee)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit;
        // allowed or liberty to buy
        if (buy)
        {
            // Option to buy or skip
            int buyNow = -prices[index] + getMaxProfit(index + 1, 0, prices, dp, fee);
            int dontBuyNow = getMaxProfit(index + 1, 1, prices, dp, fee);
            profit = max(buyNow, dontBuyNow);
        }
        else
        {
            // Option to sell or skip
            int sellNow = prices[index] - fee + getMaxProfit(index + 1, 1, prices, dp, fee);
            int dontSellNow = getMaxProfit(index + 1, 0, prices, dp, fee);
            profit = max(sellNow, dontSellNow);
        }

        return dp[index][buy] = profit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit;
                // allowed or liberty to buy
                if (buy)
                {
                    int buyNow = -prices[index] + dp[index + 1][0];
                    int dontBuyNow = dp[index + 1][1];
                    profit = max(buyNow, dontBuyNow);
                }
                else
                {
                    // Option to sell or skip
                    int sellNow = prices[index] - fee + dp[index + 1][1];
                    int dontSellNow = dp[index + 1][0];
                    profit = max(sellNow, dontSellNow);
                }

                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};