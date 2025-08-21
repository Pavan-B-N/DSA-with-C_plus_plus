// https://www.naukri.com/code360/problems/rod-cutting-problem_800284?leftPanelTabValue=PROBLEM
/*
Problem statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
*/
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include <vector>
#include <climits>
using namespace std;

// Memoization
class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size(); // n = rodLength
        // dp[index][N], Where N=rodLength
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getMaxProfit(n - 1, n, price, dp);
    }

    // N = given rod length
    int getMaxProfit(int index, int N, vector<int> &price, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            // at index==0, rodLength = 1
            return N * price[0]; // infinite supply
        }

        if (dp[index][N] != -1)
        {
            return dp[index][N];
        }

        int notPick = 0 + getMaxProfit(index - 1, N, price, dp);
        int pick = INT_MIN;
        int rodLength = index + 1; // 1 based indexing
        if (rodLength <= N)
        {
            // infinite supply of an item
            pick = price[index] + getMaxProfit(index, N - rodLength, price, dp);
        }

        return dp[index][N] = max(pick, notPick);
    }
};

// tabulation

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // base case
        for (int N = 1; N <= n; N++)
        {
            dp[0][N] = N * price[0];
        }

        for (int index = 1; index < n; index++)
        {
            for (int N = 1; N <= n; N++)
            {
                int notPick = 0 + dp[index - 1][N];
                int pick = INT_MIN;
                int rodLength = index + 1;
                if (N >= rodLength)
                {
                    pick = price[index] + dp[index][N - rodLength];
                }

                dp[index][N] = max(pick, notPick);
            }
        }

        return dp[n - 1][n];
    }
};