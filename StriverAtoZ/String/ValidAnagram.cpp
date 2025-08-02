// https://leetcode.com/problems/valid-anagram/description/
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freq; // char,freq
        for (char ch : s)
        {
            freq[ch]++;
        }

        for (char ch : t)
        {
            freq[ch]--;
            if (freq[ch] < 0)
            {
                return false;
            }
        }
        return true;
    }
};