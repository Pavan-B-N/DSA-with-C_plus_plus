// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <vector>
using namespace std;
// tag: [favorite]
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