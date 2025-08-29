// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <vector>
using namespace std;

class Solution
{
public:
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
            if (mid - 1 >= 0 && nums[mid - 1] > nums[mid])
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