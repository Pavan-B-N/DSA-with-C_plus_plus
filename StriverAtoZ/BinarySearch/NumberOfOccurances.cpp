// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
/*
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // lower_bound>=target
        int n = arr.size();
        int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        if (lb == n || arr[lb] != target)
        {
            return 0;
        }
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        return ub - lb;
    }
};

// raw implementation
class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        int first = binarySearch(arr, target, true);
        if (first == -1)
        {
            return 0;
        }
        int last = binarySearch(arr, target, false);
        return last - first + 1;
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
