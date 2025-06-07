// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = binarySearch(nums, target);
        if(first==-1){
            return {-1,-1};
        }
        int last = binarySearch(nums, target, false);
        return {first, last};
    }

    int binarySearch(vector<int> &nums, int target, bool firstIndex = true)
    {
        int start = 0;
        int end = nums.size() - 1;
        int foundIndex = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                foundIndex = mid;
                if (firstIndex)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return foundIndex;
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        // >=target
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // If target not found
        // lb == n, hypothetical index
        if (lb == n || nums[lb] != target)
            return {-1, -1};

        // >target
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return {lb, ub - 1};
    }
};
