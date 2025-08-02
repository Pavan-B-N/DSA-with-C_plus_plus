// https://leetcode.com/problems/longest-repeating-character-replacement/
#include <vector>
#include <unordered_map>
using namespace std;
/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

// Time Complexity: O(n × 26)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> freq(26, 0);

        // O(n)
        for (int right = 0; right < s.length(); right++)
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowLength = right - left + 1;

            // If replacements needed > k, shrink the window
            // O(windowLength * 26), windowLength overall is n
            while (windowLength - maxFreq > k)
            {
                freq[s[left] - 'A']--;

                // 🔁 Recalculate maxFreq
                // we don't have to update maxFreq because,
                // the updated maxFreq is always lesser
                // so windowLen - smallerMaxFreq doesn't contribute to loop
                for (int i = 0; i < 26; i++)
                {
                    maxFreq = max(maxFreq, freq[i]);
                }

                left++;
                windowLength = right - left + 1;
            }

            maxLen = max(maxLen, windowLength);
        }

        return maxLen;
    }
};

// Time Complexity: O(n)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        for (int right = 0; right < s.length(); right++)
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Only shrink if more than k replacements needed
            while ((right - left + 1) - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                // we don't have to update maxFreq because,
                // the updated maxFreq is always lesser
                // so windowLen - smallerMaxFreq doesn't contribute to loop
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Time Complexity: O(n)
// Optimal
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
            if (windowLength - maxFreq > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }
            else
            {
                maxLen = max(maxLen, windowLength);
            }
        }
        return maxLen;
    }
};