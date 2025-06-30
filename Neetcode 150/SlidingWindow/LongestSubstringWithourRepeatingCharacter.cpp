// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hashSet;
        int left = 0;
        int len = 0;
        for (int right = 0; right < s.size(); right++)
        {
            char ch = s[right];
            while (hashSet.find(ch) != hashSet.end())
            {
                hashSet.erase(s[left]);
                left++;
            }
            hashSet.insert(ch);
            len = max(len, right - left + 1);
        }
        return len;
    }
};