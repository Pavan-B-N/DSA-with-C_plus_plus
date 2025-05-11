// https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> sequence;
    findCombinations(candidates, target, 0, sequence, res);
    return res;
}

// based on the concept of subsequences
// T.C = 2 ^ Target = exponential
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

    // pick
    if (target >= arr[index])
    {
        // we are carrying the position of index as it is because we need to check if we can make target with multiple combinations of the same candidate
        sequence.push_back(arr[index]);
        findCombinations(arr, target - arr[index], index, sequence, res);
        sequence.pop_back();
    }
    // not pick
    findCombinations(arr, target, index + 1, sequence, res);
}
