// https://leetcode.com/problems/search-insert-position/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // algorithm states to return the index
    // if ele found return its inde
    // if ele not found return its next greater ele index where i can insert
    // so its indirect question of lower bound index>=target
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int lb = n;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                lb = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return lb;
    }
};

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};