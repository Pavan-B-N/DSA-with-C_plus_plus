// https://leetcode.com/problems/contains-duplicate/
#include <unordered_set>
#include <algorithm>
using namespace std;

// with unordered_set
// time complexity = O(n)
// space complexity = O(n)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

// time complexity = O(nlongn)
// space complexity = O(1)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
};