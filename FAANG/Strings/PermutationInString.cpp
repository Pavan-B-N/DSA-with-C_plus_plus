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
            
            unordered_map<char, int> s1Map;
            unordered_map<char, int> s2Map;
            
            // if i can find the substring in the s2 withing the length of my s1, then no need to go further
            for (int i = 0; i < s1.length(); i++) {
                s1Map[s1[i]]++;
                s2Map[s2[i]]++;
            }
            
            if (s1Map == s2Map) {
                return true;
            }
            
            // sliding window
            // length of sliding window is the length of s1
            // we need to make sure that even the permutation of s1 should be continuous
            int left = 0;
            for (int right = s1.length(); right < s2.length(); right++) {
                s2Map[s2[right]]++;
                s2Map[s2[left]]--;
                // Erasing removes keys with 0 value, so that the maps have the same keys and counts.
                if (s2Map[s2[left]] == 0) {
                    s2Map.erase(s2[left]);
                }
                
                left++;
                
                if (s1Map == s2Map) {
                    return true;
                }
            }
            
            return false;        
        }
    };