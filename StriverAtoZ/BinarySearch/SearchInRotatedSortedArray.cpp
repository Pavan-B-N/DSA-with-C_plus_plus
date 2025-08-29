// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <vector>
using namespace std;
// tag: [favorite]
// preferred
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            // skip duplicates
            if (nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                start++;
                end--;
            }
            // left part is sorted
            else if (nums[start] <= nums[mid])
            {
                if (nums[start] <= target && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                // right part is sorted
                if (nums[mid] < target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Time complexity is O(log n) in the best/average case, but due to duplicates your pivot logic sometimes degrades to O(n) (when the array has many equal elements).
// Average case: O(log n).
// Worst case (all elements same, e.g. [2,2,2,2,2]): O(n).
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums);
        int n = nums.size();
        // no rotation
        if (pivot == -1)
        {
            int index =
                lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            return (index < n && nums[index] == target) ? true : false;
        }

        // search in left part [0 .. pivot]
        int index =
            lower_bound(nums.begin(), nums.begin() + pivot + 1, target) -
            nums.begin();
        if (index <= pivot && nums[index] == target)
        {
            return true;
        }

        // search in right part [pivot+1 .. n-1]
        index = lower_bound(nums.begin() + pivot + 1, nums.end(), target) -
                nums.begin();

        return index < n && nums[index] == target ? true : false;
    }

    int findPivot(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // Case 1: pivot condition
            if (mid + 1 < n && nums[mid] > nums[mid + 1])
                return mid;
            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
                return mid - 1;

            // Case 2: if duplicates block decision
            if (nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                // shrink search space, but still binary search
                if (start + 1 <= end && nums[start] > nums[start + 1])
                    return start;
                start++;
                if (end - 1 >= start && nums[end - 1] > nums[end])
                    return end - 1;
                end--;
            }
            // Case 3: left half is sorted, so pivot must be in right half
            else if (nums[start] <= nums[mid])
            {
                start = mid + 1;
            }
            // Case 4: right half is sorted, so pivot must be in left half
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};

// works only for array with distinct elements
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums);
        int n = nums.size();

        // no rotation
        if (pivot == -1)
        {
            int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            return (index < n && nums[index] == target) ? index : -1;
        }

        // search in left part [0 .. pivot]
        int index = lower_bound(nums.begin(), nums.begin() + pivot + 1, target) - nums.begin();
        if (index <= pivot && nums[index] == target)
        {
            return index;
        }

        // search in right part [pivot+1 .. n-1]
        index = lower_bound(nums.begin() + pivot + 1, nums.end(), target) - nums.begin();

        return index < n && nums[index] == target ? index : -1;
    }

    int findPivot(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;

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
