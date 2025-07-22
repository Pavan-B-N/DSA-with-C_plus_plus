// https://leetcode.com/problems/majority-element-ii/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int threshold = n / 3;
        unordered_map<int, int> freq;

        for (auto &ele : nums)
        {
            freq[ele]++;
        }

        vector<int> res;
        for (auto &pair : freq)
        {
            int ele = pair.first;
            int freq = pair.second;
            if (freq > threshold)
            {
                res.push_back(ele);
            }
        }
        return res;
    }
};