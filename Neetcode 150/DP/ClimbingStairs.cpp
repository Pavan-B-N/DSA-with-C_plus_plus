// https://leetcode.com/problems/climbing-stairs/
#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
    int helper(int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int step1 = helper(n - 1, dp);
        int step2 = helper(n - 2, dp);
        return dp[n] = step1 + step2;
    }
};

// tabulation
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// optimized tabulation
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        int a = 1;
        int b = 2;

        for (int i = 3; i <= n; i++)
        {
            int res = a + b;
            a = b;
            b = res;
        }
        return b;
    }
};