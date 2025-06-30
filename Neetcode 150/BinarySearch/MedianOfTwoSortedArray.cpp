// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> nums3;

        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i++]);
            }
            else
            {
                nums3.push_back(nums2[j++]);
            }
        }

        while (i < n1)
        {
            nums3.push_back(nums1[i++]);
        }
        while (j < n2)
        {
            nums3.push_back(nums2[j++]);
        }

        int n3 = nums3.size();
        if (n3 % 2 == 1)
        {
            return nums3[n3 / 2];
        }
        else
        {
            int a = nums3[n3 / 2];
            int b = nums3[(n3 / 2) - 1];
            return (double(a + b)) / 2;
        }
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Ensure binary search is on the smaller array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = n1;
        int total = n1 + n2;
        int half = (total + 1) / 2;

        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = half - mid1;

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
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }

        return 0.0; // Fallback (should never reach here if inputs are valid)
    }
};
