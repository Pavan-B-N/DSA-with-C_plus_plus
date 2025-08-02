// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <vector>
// tag: [favorite]

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Ensure binary search is on the smaller array to minimize time
        // complexity
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        // performing binary search on the smallest array
        int start = 0;
        int end = n1;
        int total = n1 + n2;
        int left = (n1 + n2 + 1) / 2;

        while (start <= end)
        {
            int mid1 = (start + end) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1)
            {
                if (total % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
            {
                end = mid1 - 1;
            }
            else
            {
                start = mid1 + 1;
            }
        }

        return 0.0; // Fallback (should never reach here if inputs are valid)
    }
};