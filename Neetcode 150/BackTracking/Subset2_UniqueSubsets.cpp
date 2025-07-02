// https://leetcode.com/problems/subsets-ii/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subsequence;
        findUniqueSubsets(0, nums, subsequence, ans);
        return ans;
    }
    void findUniqueSubsets(int index, vector<int> &nums, vector<int> &subsequence, vector<vector<int>> &ans)
    {
        // if i need to consider the subsequence only when target == 0 then its a BackTracking/CombinationSum2.cpp
        ans.push_back(subsequence);

        for (int i = index; i < nums.size(); i++)
        {
            // skip duplicates
            if (i > index && nums[i - 1] == nums[i])
            {
                continue;
            }
            subsequence.push_back(nums[i]);
            findUniqueSubsets(i + 1, nums, subsequence, ans);
            subsequence.pop_back();
        }
    }
};