// https://leetcode.com/problems/palindrome-partitioning/
/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
partion1: ["a","a","b"]
partion2: ["a","a","b"]
*/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        findSubstrings(0, s, path, res);
        return res;
    }

    void findSubstrings(int index, string s, vector<string> &substr,
                        vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(substr);
        }

        for (int i = index; i < s.size(); i++)
        {
            // checking if i can do partion
            if (isPalindrome(s, index, i))
            {
                substr.push_back(s.substr(index, i - index + 1));
                findSubstrings(i + 1, s, substr, res);
                substr.pop_back(); // backtrack
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
};