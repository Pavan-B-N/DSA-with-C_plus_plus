// https://leetcode.com/problems/edit-distance/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// DPOnStrings\MinOperationsToConverStringAToB.cpp
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findMinOperations(n - 1, m - 1, word1, word2, dp);
    }

    int findMinOperations(int i, int j, string &s1, string &s2,
                          vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s1[i] == s2[j])
        {
            return dp[i][j] = 0 + findMinOperations(i - 1, j - 1, s1, s2, dp);
        }

        int insert = 1 + findMinOperations(i, j - 1, s1, s2, dp);
        int del = 1 + findMinOperations(i - 1, j, s1, s2, dp);
        int replace = 1 + findMinOperations(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = min({insert, del, replace});
    }
};

// tabulation
int minDistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base condition
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    // base condition
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 0 + dp[i - 1][j - 1];
            }
            else
            {

                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];

                dp[i][j] = min({insert, del, replace});
            }
        }
    }

    return dp[n][m];
}
