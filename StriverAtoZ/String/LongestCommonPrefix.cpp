// https://leetcode.com/problems/longest-common-prefix/
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Input: strs = ["flower","flow","flight"]
Output: "fl"


Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

// input : ["reflower","flow","flight"]
// output : ""
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// sorting visits all strings and all characters repeatedly.
class Solution
{
public:
    // O(n log n + m)
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        sort(strs.begin(), strs.end());

        string res = "";
        string first = strs[0];
        // input : ["reflower","flow","flight"]
        // output : ""
        string last = strs[strs.size() - 1];

        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] != last[i])
            {
                break;
            }
            res += first[i];
        }

        return res;
    }
};

// 	✅ O(n * m)
// optimal
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].length(); ++i)
        {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); ++j)
            {
                // Check if index is out of range or character doesn't match
                if (i >= strs[j].length() || strs[j][i] != currentChar)
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0]; // All characters matched
    }
};
