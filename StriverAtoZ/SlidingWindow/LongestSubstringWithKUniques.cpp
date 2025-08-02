// Exactly K chars
// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// AT most K unique chars
// https://www.naukri.com/code360/problems/distinct-characters_2221410?leftPanelTabValue=PROBLEM
#include <vector>
#include <unordered_map>
using namespace std;
/*
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
*/
// O(2n) , while
class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        unordered_map<char, int> freqMap; // {char, freq}
        int left = 0;
        int maxLen = -1; //return -1 if not found

        for (int right = 0; right < s.size(); right++)
        {
            freqMap[s[right]]++;

            // shrink window if distinct chars > k
            while (freqMap.size() > k)
            {
                freqMap[s[left]]--;
                if (freqMap[s[left]] == 0)
                    freqMap.erase(s[left]);
                left++;
            }

            // Your task is to find the length of the longest substring that contains exactly k distinct characters.
            if (freqMap.size() == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};

// O(n), if
class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        unordered_map<char, int> freqMap; // {char, freq}
        int left = 0;
        int maxLen = -1; // as per some versions of the problem, return -1 if not found

        for (int right = 0; right < s.size(); right++)
        {
            freqMap[s[right]]++;

            // shrink window if distinct chars > k
            if (freqMap.size() > k)
            {
                freqMap[s[left]]--;
                if (freqMap[s[left]] == 0)
                    freqMap.erase(s[left]);
                left++;
            }

            // Your task is to find the length of the longest substring that contains exactly k distinct characters.
            if (freqMap.size() == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};

