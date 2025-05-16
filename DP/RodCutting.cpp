// https://www.naukri.com/code360/problems/rod-cutting-problem_800284?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;

int getMaxProfit(int index, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return N * price[0];
    }

    if (dp[index][N] != -1)
    {
        return dp[index][N];
    }

    int notPick = 0 + getMaxProfit(index - 1, N, price, dp);
    int pick = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= N)
    {
        // infinite supply of an item
        pick = price[index] + getMaxProfit(index, N - rodLength, price, dp);
    }

    return dp[index][N] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return getMaxProfit(n - 1, n, price, dp);
    // Write your code here.
}


// tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // base case
    for (int N = 0; N <= n; N++)
    {
            dp[0][N] = N  * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notPick = 0 + dp[index - 1][N];
            int pick = INT_MIN;
            int rodLength  = index + 1;
            if (N >= rodLength )
            {
                pick = price[index] + dp[index][N - rodLength];
            }

            dp[index][N] = max(pick, notPick);
        }
    }

    return dp[n - 1][n];

}
