// https://leetcode.com/problems/merge-sorted-array/
/*
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
To accommodate this, nums1 has a length of m + n

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/
#include <vector>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = (m + n) - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
        // no need to handle for ith guy because he is in right place
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};