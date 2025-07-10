// https://leetcode.com/problems/decode-ways/
#include <vector>
#include <string>
using namespace std;

// memoization
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, dp);
    }

    int helper(int index, string &s, vector<int> &dp)
    {
        if (index == s.size())
            return 1;
        if (dp[index] != -1)
            return dp[index];

        int count = 0;

        // Single digit decode (must not be '0')
        if (s[index] != '0')
        {
            count += helper(index + 1, s, dp);

            // Double digit decode
            if (index + 1 < s.size())
            {
                int digit2 = stoi(s.substr(index, 2));
                if (digit2 >= 10 && digit2 <= 26)
                {
                    count += helper(index + 2, s, dp);
                }
            }
        }

        return dp[index] = count;
    }
};

// tabulation
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0); // dp[i] = number of ways to decode up to s[0..i-1]
        // shift index
        dp[0] = 1; // Empty string has one way to decode
        dp[1] = 1; // First char is already checked for '0'

        for (int i = 2; i <= n; i++)
        {
            // One-digit decode (s[i-1])
            if (s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }

            // Two-digit decode (s[i-2] and s[i-1])
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};
