// https://leetcode.com/problems/move-zeroes/
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int k = 0;
        for (int ele : nums)
        {
            if (ele != 0)
            {
                nums[k++] = ele;
            }
        }

        while (k < nums.size())
        {
            nums[k++] = 0;
        }
    }
};