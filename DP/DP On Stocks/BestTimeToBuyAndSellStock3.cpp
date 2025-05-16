// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <iostream>
#include <vector>
using namespace std;

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

    int getMaxProfit(int index, int buy, int maxTransactions, vector<int> &prices,
                     vector<vector<vector<int>>> &dp)
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
                -prices[index] + getMaxProfit(index + 1, 0, maxTransactions, prices, dp);
            int skipBuy = getMaxProfit(index + 1, 1, maxTransactions, prices, dp);
            profit = max(buyNow, skipBuy);
        }
        else
        {
            // Option to sell or skip
            int sellNow =
                prices[index] + getMaxProfit(index + 1, 1, maxTransactions - 1, prices, dp);
            int skipSell = getMaxProfit(index + 1, 0, maxTransactions, prices, dp);
            profit = max(sellNow, skipSell);
        }

        dp[index][buy][maxTransactions] = profit;
        return profit;
    }
};