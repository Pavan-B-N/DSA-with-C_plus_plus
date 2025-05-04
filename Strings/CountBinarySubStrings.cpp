/*
Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced

Input: str = “0100110101”
Output: 4
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010”
Output: 3

Input: str = “0000000000”
Output: -1

*/
#include <iostream>
using namespace std;
// https://leetcode.com/problems/count-binary-substrings/

// Time complexity: O(N)
// Two Pointer approach and sliding window
int countBinarySubstrings(string s)
{
    int prev_count = 0;
    int curr_count = 1;
    int ans = 0;

    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            curr_count++;
        }
        else
        {
            ans += min(prev_count, curr_count);
            prev_count = curr_count;
            curr_count = 1;
        }
    }

    ans += min(prev_count, curr_count);
    return ans;
}
