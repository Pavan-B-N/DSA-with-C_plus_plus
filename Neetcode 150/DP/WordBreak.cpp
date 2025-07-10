// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// memoization
// O(n × L).
// L=  Max length of any word in dict
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1); // -1 = uncomputed, 0 = false, 1 = true

        return canBreak(0, s, dict, dp);
    }

    bool canBreak(int index, string &s, unordered_set<string> &dict, vector<int> &dp)
    {
        if (index == s.size())
            return true;

        if (dp[index] != -1)
            return dp[index];

        for (int end = index + 1; end <= s.size(); ++end)
        {
            string word = s.substr(index, end - index);
            if (dict.count(word) && canBreak(end, s, dict, dp))
            {
                return dp[index] = 1;
            }
        }

        return dp[index] = 0;
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty prefix is segmentable

        for (int index = 0; index < n; ++index)
        {
            if (!dp[index])
                continue; // No point checking from here

            for (int end = index + 1; end <= n; ++end)
            {
                string word = s.substr(index, end - index); // same as recursion
                if (dict.count(word))
                {
                    dp[end] = true;
                }
            }
        }

        return dp[n]; // is the whole string breakable?
    }
};
