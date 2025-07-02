// https://leetcode.com/problems/subsets/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        findSubsets(0, nums, subset, ans);
        return ans;
    }
    void findSubsets(int index, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(subset);
            return;
        }

        // not pick
        findSubsets(index + 1, nums, subset, ans);

        // pick
        subset.push_back(nums[index]);
        findSubsets(index + 1, nums, subset, ans);
        // backtrack -> reset state
        subset.pop_back();
    }
};