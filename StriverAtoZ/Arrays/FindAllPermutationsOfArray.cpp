// https://leetcode.com/problems/permutations/description/
/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include <vector>
#include <algorithm>
using namespace std;

//  Time Complexity: O(n! * n)
// O(n!) (output)
// n! — Total number of permutations of n unique elements.
// n — Time to construct each permutation (copying currPermutation into ans).
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        findAllPermutations(0, nums, ans);
        return ans;
    }
    void findAllPermutations(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            findAllPermutations(index + 1, nums, ans);
            // backtrack
            swap(nums[index], nums[i]);
        }
    }
};


// lexicographic order 
//  Time Complexity: O(n! * n)
// Space Complexity: O(n), currPermutation 
// O(n! * n) (output) + O(n) (temp space)
// n! — Total number of permutations of n unique elements.
// n — Time to construct each permutation (copying currPermutation into ans).
// for dictionary order we need to make use of visited or used vector
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currPermutation;
        vector<bool> used(nums.size(), false);
        
        sort(nums.begin(), nums.end()); // Important for dictionary order
        findAllPermutations(nums, used, currPermutation, ans);
        return ans;
    }

private:
    void findAllPermutations(vector<int>& nums, vector<bool>& used, vector<int>& currPermutation, vector<vector<int>>& ans) {
        if (currPermutation.size() == nums.size()) {
            ans.push_back(currPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            currPermutation.push_back(nums[i]);
            findAllPermutations(nums, used, currPermutation, ans);
            currPermutation.pop_back();
            used[i] = false;
        }
    }
};
