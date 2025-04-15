// https://leetcode.com/problems/reverse-string-ii/description/
/*
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"
*/
#include <string>
using namespace std;
class Solution {
    public:
        string reverseStr(string s, int k) {
            int n = s.length();
            for (int i = 0; i < n; i += 2 * k) {
                // len is always at most k characters (normal case)
                // or (n - i) characters (if few characters are left at the end)
                reversePartOfStr(s, i, min(k, n - i));
            }
            return s;
        }
    
        void reversePartOfStr(string &s, int start, int len) {
            int i = start;
            int j = start + (len - 1);
            while (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
    };
    