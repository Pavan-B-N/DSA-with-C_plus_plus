// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <unordered_map>
using namespace std;
// O(n)
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> map; // char -> index
    int i = 0, maxlen = 0;

    for (int j = 0; j < s.length(); j++)
    {
        char ch = s[j];
        if (map.find(ch) != map.end())
        {
            i = max(i, map[ch] + 1); // move i past the last occurrence
        }
        map[ch] = j;
        maxlen = max(maxlen, j - i + 1);
    }

    return maxlen;
}