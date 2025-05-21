// https://leetcode.com/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // set_intersection works only with set and doesn't work with unorderd_set
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> result;

        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                         back_inserter(result));

        return result;
    }

    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> result;
        for (auto ele : nums2)
        {
            if (s.find(ele) != s.end())
            {
                result.push_back(ele);
                s.erase(ele);
            }
        }
        return result;
    }
};