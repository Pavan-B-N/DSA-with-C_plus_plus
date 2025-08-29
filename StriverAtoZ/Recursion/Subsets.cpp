#include <vector>
#include <algorithm>
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

// if the array contains duplicates
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subsequence;
        findUniqueSubsets(0, nums, subsequence, ans);
        return ans;
    }
    void findUniqueSubsets(int index, vector<int> &nums, vector<int> &subsequence, vector<vector<int>> &ans)
    {
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