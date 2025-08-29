// https://leetcode.com/problems/combination-sum-iii/description/
/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // k= combination size
        // n=target
        vector<int> arr, sequence;
        vector<vector<int>> res;
        for (int i = 1; i <= 9; i++)
            arr.push_back(i);

        findCombinations(0, n, k, arr, sequence, res);
        return res;
    }

private:
    void findCombinations(int index, int target, int k,
                          vector<int> &arr, vector<int> &sequence,
                          vector<vector<int>> &res)
    {
        if (index == arr.size() || sequence.size() == k)
        {
            if (sequence.size() == k && target == 0)
                res.push_back(sequence);
            return;
        }

        // not pick
        findCombinations(index + 1, target, k, arr, sequence, res);

        // pick
        if (target >= arr[index])
        {
            sequence.push_back(arr[index]);
            findCombinations(index + 1, target - arr[index], k, arr, sequence, res);
            sequence.pop_back();
        }
    }
};

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // k= combination size
        // n=target
        vector<int> sequence;
        vector<vector<int>> res;

        findCombinations(1, n, k, sequence, res);
        return res;
    }

private:
    void findCombinations(int index, int target, int k,
                          vector<int> &sequence,
                          vector<vector<int>> &res)
    {
        if (index == 10 || sequence.size() == k)
        {
            if (sequence.size() == k && target == 0)
                res.push_back(sequence);
            return;
        }

        // not pick
        findCombinations(index + 1, target, k, sequence, res);

        // pick
        if (target >= index)
        {
            sequence.push_back(index);
            findCombinations(index + 1, target - index, k, sequence, res);
            sequence.pop_back();
        }
    }
};
