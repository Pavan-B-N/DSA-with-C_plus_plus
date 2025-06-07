// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int peak = findPivot(nums, target);

        // the stl binary_search returns boolean
        // so to find index we can make use of lower_bound
        int ans = binarySearch(0, peak, nums, target);
        if (ans == -1)
        {
            ans = binarySearch(peak + 1, n - 1, nums, target);
        }
        return ans;
    }

    // this algorithm works only for distinct elements
    // if array contains duplicates it won't work
    int findPivot(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mid + 1 < n && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[start] > nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }

    int binarySearch(int start, int end, vector<int> &nums, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
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
        return -1;
    }
};

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int peak = findPivot(nums, target);
        int ans = lower_bound(nums.begin(), nums.begin() + peak + 1, target) -
                  nums.begin();
        if (ans == peak + 1 || nums[ans] != target)
        {
            ans = lower_bound(nums.begin() + peak + 1, nums.end(), target) -
                  nums.begin();
        }

        if (ans == n || nums[ans] != target)
        {
            return -1;
        }
        return ans;
    }
    int findPivot(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mid + 1 < n && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[start] > nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};