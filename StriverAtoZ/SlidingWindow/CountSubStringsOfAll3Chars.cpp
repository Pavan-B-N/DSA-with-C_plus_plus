// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
#include <vector>
#include <unordered_map>
using namespace std;
/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
*/
// O(2n) , while
class Solution
{ 
public:
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> freqMap;
        int n = s.size();
        int substrings = 0;
        int left = 0;

        for (int right = 0; right < n; ++right)
        {
            freqMap[s[right]]++;

            // shrink window from left while it contains all 3 characters
            while (freqMap.size() == 3)
            {
                substrings += (n - right); // all substrings from left to n-1 are valid
                freqMap[s[left]]--;
                if (freqMap[s[left]] == 0)
                    freqMap.erase(s[left]);
                left++;
            }
        }

        return substrings;
    }
};
