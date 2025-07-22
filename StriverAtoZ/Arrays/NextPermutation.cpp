// https://leetcode.com/problems/next-permutation/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // STL
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};

// Time complexity: O(n)
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int pivot = -1; // stores pivot index
        int n = nums.size();

        // find pivot
        // pivot = nums[i] > num[i+1] from right most of the    array
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }
        // if pivot not found then its the last permutation
        // so for last permutation we need to return first permutation like circural permutation
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // step 2 : find right most element > pivot
        // always exists
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        // step 3 : reverse pivot+1 to n-1
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};