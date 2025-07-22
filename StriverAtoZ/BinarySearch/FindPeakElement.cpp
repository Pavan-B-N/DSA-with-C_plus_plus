// https://leetcode.com/problems/find-peak-element/
#include <vector>
using namespace std;
// tag: [favorite]

// O(logn)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return end;
    }
};

// O(n)
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || nums[i] > nums[i - 1]) && (i == n - 1 || nums[i] > nums[i + 1]))
            {
                return i;
            }
        }
        return -1;
    }
};