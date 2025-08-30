/*
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int totalProfit = 0;
        // On each day, you may decide to buy and/or sell the stock.
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - prices[i - 1];
            totalProfit += max(profit, 0);
        }
        return totalProfit;
    }
};

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
        if (index == prices.size())
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
            int sellNow = prices[index] + getMaxProfit(index + 1, 1, prices, dp);
            int dontSellNow = getMaxProfit(index + 1, 0, prices, dp);
            profit = max(sellNow, dontSellNow);
        }

        return dp[index][buy] = profit;
    }
};