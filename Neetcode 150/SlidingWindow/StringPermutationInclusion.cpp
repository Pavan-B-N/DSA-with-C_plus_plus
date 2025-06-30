// https://leetcode.com/problems/permutation-in-string/
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
        {
            return false;
        }
        unordered_map<char, int> map1; // freq of s1
        unordered_map<char, int> map2; // freq of s2

        for (int i = 0; i < s1.size(); i++)
        {
            map1[s1[i]]++;
            map2[s2[i]]++;
        }
        if (map1 == map2)
        {
            return true;
        }

        int left = 0;
        for (int right = s1.length(); right < s2.length(); right++)
        {
            map2[s2[right]]++;
            map2[s2[left]]--;

            if (map2[s2[left]] == 0)
            {
                map2.erase(s2[left]);
            }
            left++;

            if (map1 == map2)
            {
                return true;
            }
        }
        return false;
    }
};