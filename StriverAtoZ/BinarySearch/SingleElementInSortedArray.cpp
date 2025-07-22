// https://leetcode.com/problems/single-element-in-a-sorted-array/
#include <vector>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            bool left = (mid - 1 >= 0) ? nums[mid] == nums[mid - 1] : false;
            bool right = (mid + 1 < n) ? nums[mid] == nums[mid + 1] : false;

            if (!left && !right)
            {
                return nums[mid];
            }
            /// before single element, elements which are repeating twice are placed at (even,odd) index
            // but after single single elements duplicate elements position becomes (odd,even)
            // left part of the single single
            else if ((mid % 2 == 0 && right) || (mid % 2 == 1 && left))
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