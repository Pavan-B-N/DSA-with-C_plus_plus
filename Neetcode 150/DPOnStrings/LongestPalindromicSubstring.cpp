// https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        string lps = "";
        int maxLen = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    if (dp[i][j] > maxLen)
                    {
                        int len = dp[i][j];
                        int endPos = i;
                        int sStart = endPos - len;
                        int tStart = n - j;
                        /*
                            s = a b a c d f g d c a b a
                                ↑             ↑
                                i-len+1        i

                            t = a b a c d g f d c a b a
                                ↑             ↑
                                j-len+1        j

                        */
                        // A common substring between s and reverse(s) is not necessarily a palindromic substring in s
                        //  So Ensure the substring comes from mirrored positions
                        if (sStart == tStart)
                        {
                            lps = s.substr(sStart, len);
                            maxLen = len;
                        }
                    }
                }
            }
        }

        return lps;
    }
};
