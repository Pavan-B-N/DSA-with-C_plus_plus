// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
*/
#include <string>
using namespace std;
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            auto pos=s.find(part);
            while(pos<s.length()){
                s.erase(pos,part.length());
                pos=s.find(part);
            }
    
            return s;
        }
    };