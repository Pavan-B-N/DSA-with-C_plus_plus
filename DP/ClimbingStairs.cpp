/*
https://leetcode.com/problems/climbing-stairs/description/


You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
#include <iostream>
#include <vector>
using namespace std;

// memoization
int climbStairs(int n) {
    vector<int> memo(n+1, -1);
    return countPossibleWays(n, memo);
}

int countPossibleWays(int n, vector<int> &memo) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];

    memo[n] = countPossibleWays(n - 1, memo) + countPossibleWays(n - 2, memo);
    return memo[n];
}
//----


// tabulation
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbStairs(int n) {
    if(n<=1){
        return n;
    }
    int a=1;
    int b=2;
    for(int i=3;i<=n;i++){
        int next=a+b;
        a=b;
        b=next;
    }

    return b;
}