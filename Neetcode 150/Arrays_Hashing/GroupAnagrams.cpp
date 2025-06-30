
// https://leetcode.com/problems/group-anagrams/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// Frequency string method
//  O(N * K log K)
// sorting technique
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        if (strs.size() <= 0)
        {
            return res;
        }

        unordered_map<string, vector<string>> map; // sortedString,strings or group
        for (string &str : strs)
        {
            string actualString = str;
            sort(str.begin(), str.end());
            map[str].push_back(actualString);
        }
        // build res
        for (auto &pair : map)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};