// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < s.length(); right++)
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            int windowLength = right - left + 1;
            if (windowLength - maxFreq <= k)
            {
                maxLen = max(maxLen, windowLength);
            }
            else
            {
                freq[s[left] - 'A']--;
                left++;
            }
        }
        return maxLen;
    }
};