// https://leetcode.com/problems/longest-string-chain/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Time complexity: O(nlogn+n^2⋅L) = O(n^2⋅L)
// isPredecessor = Each call takes at most O(L) where L = max word length
// Space Complexity: O(n)
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        //  sorting by length
        sort(words.begin(), words.end(), comparator); // use comparator

        vector<int> dp(n, 1), prev(n, -1);
        int maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPredecessor(words[j], words[i]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    // Comparator for sorting by length
    static bool comparator(const string &a, const string &b)
    {
        return a.size() < b.size();
    }

    bool isPredecessor(string &a, string &b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0, j = 0, mismatch = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                mismatch++;
                j++;
                if (mismatch > 1)
                    return false;
            }
        }
        return true;
    }
};
