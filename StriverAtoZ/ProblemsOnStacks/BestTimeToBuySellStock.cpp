// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 1)
        {
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i]; // buy
            }
            else
            {
                // sell
                int profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};