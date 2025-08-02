// https://leetcode.com/problems/minimum-window-substring/description/
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

*/
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> freqMap;
        for (auto ch : t)
        {
            freqMap[ch]++;
        }
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        for (int right = 0; right < s.size(); right++)
        {
            // Reduce freq for current char
            freqMap[s[right]]--;

            // Count only when char is part of t and still needed
            if (freqMap[s[right]] >= 0)
            {
                count++;
            }

            while (count == t.size())
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                freqMap[s[left]]++;
                if (freqMap[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
        }
        return startIndex > -1 ? s.substr(startIndex, minLen) : "";
    }
};