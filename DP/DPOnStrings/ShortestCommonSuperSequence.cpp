
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();

        int superSequenceLength = n + m - longestCommonSubsequence(str1, str2);
        return superSequenceLength;
    }

    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // shift index method
                // n-1 = n, -1 = 0
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
 

int main() {
    string str1 = "abcde";
    string str2 = "ace";
    
    Solution sol;
    int result = sol.shortestCommonSupersequence(str1, str2);
    cout << "Length of Shortest Common Supersequence: " << result << endl;

    return 0;
}
