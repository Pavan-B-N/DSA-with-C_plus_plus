// https://leetcode.com/problems/palindrome-partitioning/
#include <vector>
#include <iostream>
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

    // recursion is going level by level that is first finds the palindrome of size 1,2,3...n
    void findSubstrings(int index, string s, vector<string> &path,
                        vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                findSubstrings(i + 1, s, path, res);
                path.pop_back(); // backtrack
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