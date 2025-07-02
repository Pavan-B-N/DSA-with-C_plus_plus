// https://leetcode.com/problems/combination-sum-ii/
#include <vector>
#include <algorithm>
using namespace std;

// TLE
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> sequence;
        findCombinations(candidates, target, 0, sequence, res);
        return res;
    }
    void findCombinations(vector<int> &arr, int target, int index,
                          vector<int> &sequence, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.push_back(sequence);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            // skip duplicate
            if (i > index && arr[i - 1] == arr[i])
                continue;

            sequence.push_back(arr[i]);
            findCombinations(arr, target - arr[i], i + 1, sequence, res);
            sequence.pop_back();
        }
    }
};