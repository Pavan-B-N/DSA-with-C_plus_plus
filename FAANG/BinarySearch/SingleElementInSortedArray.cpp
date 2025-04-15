// https://leetcode.com/problems/single-element-in-a-sorted-array/
/*

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


*/
#include <iostream>
#include <vector>
using namespace std;
/*

Why it works?
Before the single element: pairing is perfect (even-odd pairs like 0-1, 2-3...).

After the single element: pairing breaks (even indexes won't match the next element).
*/
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();

    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        bool checkLeft = (mid > 0) && nums[mid] == nums[mid - 1];
        bool checkRight = (mid + 1 < n) && nums[mid] == nums[mid + 1];

        bool even=mid % 2 == 0;
        bool odd=mid % 2 == 1;

        if (!checkLeft && !checkRight)
        {
            return nums[mid];
        }
        else if ((even && checkRight) || (odd && checkLeft))
        {
            // my single element is on right side
            start = mid + 1;
        }
        else
        {
            // my single element is on left side
            end = mid - 1;
        }
    }
    return -1;
}
