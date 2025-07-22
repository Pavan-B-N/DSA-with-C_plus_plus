// https://leetcode.com/problems/search-insert-position/
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

class Solution
{
public:
    int searchInsert(vector<int> &arr, int target)
    {
        // lowerBound >= target
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= target)
            {
                // ans = mid
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start; // or ans
    }
};