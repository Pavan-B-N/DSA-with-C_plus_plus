
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <vector>
#include <algorithm>
using namespace std;
// solve it using binary search in future
// brute force
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