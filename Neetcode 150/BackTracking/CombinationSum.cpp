// https://leetcode.com/problems/combination-sum/description/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> sequence;
        findCombinations(candidates, target, 0, sequence, res);
        return res;
    }
    void findCombinations(vector<int> &arr, int target, int index, vector<int> &sequence, vector<vector<int>> &res)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                res.push_back(sequence);
            }
            return;
        }
        // not pick
        findCombinations(arr, target, index + 1, sequence, res);

        // pick
        if (target >= arr[index])
        {
            sequence.push_back(arr[index]);
            findCombinations(arr, target - arr[index], index, sequence, res);
            sequence.pop_back();
        }
    }


};