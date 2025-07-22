// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // If target not found
        if (lb == n || nums[lb] != target)
            return {-1, -1};

        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return {lb, ub - 1};
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = binarySearch(nums, target, true);
        if (first == -1)
        {
            return {-1, -1};
        }
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
    int binarySearch(vector<int> &nums, int target, bool isFirstMatch = true)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                if (isFirstMatch)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};