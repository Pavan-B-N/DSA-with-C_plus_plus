// https://leetcode.com/problems/permutations/description/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        findPermutations(nums, ans, 0);
        return ans;
    }

    void findPermutations(vector<int> &nums, vector<vector<int>> &ans, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(nums); // only push full permutations
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            findPermutations(nums, ans, index + 1);
            swap(nums[i], nums[index]); // backtrack
        }
    }
};