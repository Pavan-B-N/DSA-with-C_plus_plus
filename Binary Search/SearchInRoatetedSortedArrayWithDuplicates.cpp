// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include <vector>
#include <algorithm>

using namespace std;


// worst case due to duplicates shrink array time complexity = O(n/2)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Target found
            if (nums[mid] == target) return true;

            // Handle duplicates: nums[start] == nums[mid] == nums[end]
            // trim the search space
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                ++start;
                --end;
            }
            // Left half is sorted
            else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            // Right half is sorted
            // nums[mid]<=nums[end]
            else {
                if (nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            } 
        }
        return false;
    }
};
