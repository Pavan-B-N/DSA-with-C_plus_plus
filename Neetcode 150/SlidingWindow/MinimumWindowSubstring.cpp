// https://leetcode.com/problems/minimum-window-substring/description/
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> freq;
        for (auto ch : t)
        {
            freq[ch]++;
        }
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int startIndex = -1;
        for (int right = 0; right < s.size(); right++)
        {
            // Reduce freq for current char
            freq[s[right]]--;

            // Count only when char is part of t and still needed
            if (freq[s[right]] >= 0)
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

                freq[s[left]]++;
                if (freq[s[left]] > 0)
                {
                    count--;
                }
                left++;
            }
        }
        return startIndex > -1 ? s.substr(startIndex, minLen) : "";
    }
};