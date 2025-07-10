// https://leetcode.com/problems/palindromic-substrings/description/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // Odd length palindromes
            expandAroundCenter(s, i, i, count);

            // Even length palindromes
            expandAroundCenter(s, i, i + 1, count);
        }

        return count;
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &count)
    {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
    }
};
