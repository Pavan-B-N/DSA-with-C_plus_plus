// https://leetcode.com/problems/partition-labels/description/
#include <vector>
#include <unordered_map>
using namespace std;

// time O(n)
//  space O(1) or O(26) so constant
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> hashMap; // stores last occurrence of each character
        for (int i = 0; i < s.size(); i++)
        {
            hashMap[s[i]] = i;
        }

        int start = 0, end = 0;
        vector<int> ans;

        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, hashMap[s[i]]);
            if (i == end)
            {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
