// https://leetcode.com/problems/binary-search/description/
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        // works on the basis of trimming the search space
        while (start <= end)
        {
            // prevents overflow,
            // if start and end points to INT_MAX the this will cause int overflow so we don't do start+end/2;
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

// recursive solution
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return search(0, nums.size() - 1, nums, target);
    }
    int search(int start, int end, vector<int> &nums, int target)
    {
        // we ran out of the search space, base case
        if (start > end)
        {
            return -1;
        }

        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            return search(start, mid - 1, nums, target);
        }
        else
        {
            return search(mid + 1, end, nums, target);
        }
    }
};