// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <unordered_set>
using namespace std;
/*
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hashSet;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < s.size(); right++)
        {
            char ch = s[right];
            while (hashSet.find(ch) != hashSet.end())
            {
                hashSet.erase(s[left++]);
            }
            hashSet.insert(ch);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};