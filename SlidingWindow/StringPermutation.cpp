// https://leetcode.com/problems/permutation-in-string/
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if (s1.length() > s2.length()) {
                return false;
            }
            
            unordered_map<char, int> s1Count;
            unordered_map<char, int> s2Count;
            
            for (int i = 0; i < s1.length(); i++) {
                s1Count[s1[i]]++;
                s2Count[s2[i]]++;
            }
            
            if (s1Count == s2Count) {
                return true;
            }
            
            // sliding window
            int left = 0;
            for (int right = s1.length(); right < s2.length(); right++) {
                s2Count[s2[right]]++;
                s2Count[s2[left]]--;
                // Erasing removes keys with 0 value, so that the maps have the same keys and counts.
                if (s2Count[s2[left]] == 0) {
                    s2Count.erase(s2[left]);
                }
                
                left++;
                
                if (s1Count == s2Count) {
                    return true;
                }
            }
            
            return false;        
        }
    };