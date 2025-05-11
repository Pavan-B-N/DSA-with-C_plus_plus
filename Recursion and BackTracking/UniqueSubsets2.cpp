// https://leetcode.com/problems/subsets-ii/description/
/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    findUniqueSubsets(nums, 0, ans, subset);
    return ans;
}

void findUniqueSubsets(vector<int> &arr, int index,
                       vector<vector<int>> &ans, vector<int> &subset)
{
    ans.push_back(subset);
    for (int i = index; i < arr.size(); i++)
    {
        // check duplicate
        if (i > index && arr[i] == arr[i - 1])
            continue;
        subset.push_back(arr[i]);
        findUniqueSubsets(arr, i + 1, ans, subset);
        subset.pop_back(); // backtrack
    }
}