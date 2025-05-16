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

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

*/
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int totalProfit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int diff = prices[i + 1] - prices[i];
        if (diff > 0)
        {
            totalProfit += diff;
        }
    }
    return totalProfit;
}

// memoization
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // dp[index][buy] = max profit from day index with buy status
    // buy = [1,0];// 1 means allowed to buy
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
    if (buy)
    {
        // Option to buy or skip
        int buyNow = -prices[index] + getMaxProfit(index + 1, 0, prices, dp);
        int skipBuy = getMaxProfit(index + 1, 1, prices, dp);
        profit = max(buyNow, skipBuy);
    }
    else
    {
        // Option to sell or skip
        int sellNow = prices[index] + getMaxProfit(index + 1, 1, prices, dp);
        int skipSell = getMaxProfit(index + 1, 0, prices, dp);
        profit = max(sellNow, skipSell);
    }

    dp[index][buy] = profit;
    return profit;
}