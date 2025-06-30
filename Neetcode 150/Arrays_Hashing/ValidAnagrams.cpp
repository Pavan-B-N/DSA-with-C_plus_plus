// https://leetcode.com/problems/valid-anagram/
#include <unordered_map>
using namespace std;

// time complexity = O(n+m) or O(2n) = O(n)
// space complexity = O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freq; // char,freq
        for (char ch : s)
        {
            freq[ch]++;
        }

        for (char ch : t)
        {
            freq[ch]--;
            if (freq[ch] < 0)
            {
                return false;
            }
        }
        return true;
    }
};