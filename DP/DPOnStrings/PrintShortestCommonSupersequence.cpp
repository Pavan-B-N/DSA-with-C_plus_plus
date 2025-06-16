// https://leetcode.com/problems/shortest-common-supersequence/submissions/1635497332/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();

        // Step 1: Create the DP table for Longest Common Subsequence (LCS)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Build the shortest common supersequence from the DP table
        string result;
        int i = n, j = m;
        // where dp[n][m] is the length of the longest common subsequence
        // if we consider only the matching once then we build the lcs
        // if we consider matching and notMatching but in the actual path of the resursin tree we get the longest common supersequence but we should ass the remaining characters
        // SCS = str1.length() + str2.length() - LCS length
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                result.push_back(str1[i - 1]);
                --i;
                --j;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                result.push_back(str1[i - 1]);
                --i;
            }
            else
            {
                result.push_back(str2[j - 1]);
                --j;
            }
        }

        // Append remaining characters from both strings
        while (i > 0)
        {
            result.push_back(str1[i - 1]);
            --i;
        }
        while (j > 0)
        {
            result.push_back(str2[j - 1]);
            --j;
        }

        // Reverse the result string before returning
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    string scs = sol.shortestCommonSupersequence(str1, str2);
    cout << "Shortest Common Supersequence: " << scs << endl;
    return 0;
}