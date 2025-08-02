// https://leetcode.com/problems/isomorphic-strings/
/*
Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
*/
// tag: [favorite]

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> hashMap;

        for (int i = 0; i < s.length(); ++i)
        {
            char original = s[i];
            char replacement = t[i];

            if (hashMap.find(original) == hashMap.end())
            {
                // simulate containsValue(replacement)
                for (const auto &entry : hashMap)
                {
                    if (entry.second == replacement)
                    {
                        return false;
                    }
                }
                hashMap[original] = replacement;
            }
            else
            {
                char mappedCharacter = hashMap[original];
                if (mappedCharacter != replacement)
                {
                    return false;
                }
            }
        }

        return true;
    }
};
