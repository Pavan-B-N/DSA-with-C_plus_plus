// https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?leftPanelTabValue=PROBLEM

#include <vector>
using namespace std;

#include <climits>
int getMaxProfit(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp);
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return getMaxProfit(n - 1, w, profit, weight, dp);
}
int getMaxProfit(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (w < weight[0])
            return 0;
        return (w / weight[0]) * profit[0];
    }

    if (dp[index][w] != -1)
    {
        return dp[index][w];
    }

    int notPick = 0 + getMaxProfit(index - 1, w, profit, weight, dp);
    int pick = INT_MIN;
    if (w >= weight[index])
    {
        // infinite supply of an item
        pick = profit[index] + getMaxProfit(index, w - weight[index], profit, weight, dp);
    }

    return dp[index][w] = max(pick, notPick);
}

// tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    // base case
    for (int wt = 0; wt <= w; wt++)
    {
        if (wt >= weight[0])
        {
            dp[0][wt] = (wt / weight[0]) * profit[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= w; wt++)
        {
            int notPick = 0 + dp[index - 1][wt];
            int pick = INT_MIN;
            if (wt >= weight[index])
            {
                pick = profit[index] + dp[index][wt - weight[index]];
            }

            dp[index][wt] = max(pick, notPick);
        }
    }

    return dp[n - 1][w];
}