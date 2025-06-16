// https://leetcode.com/problems/perfect-squares/
#include <vector>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }

    int helper(int n, vector<int> &memo)
    {
        if (n == 0)
            return 0;
        if (memo[n] != -1)
            return memo[n];

        int minCount = INT_MAX;
        for (int i = 1; i * i <= n; ++i)
        {
            minCount = min(minCount, 1 + helper(n - i * i, memo));
        }

        return memo[n] = minCount;
    }
};

// tabulation
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // base case

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
