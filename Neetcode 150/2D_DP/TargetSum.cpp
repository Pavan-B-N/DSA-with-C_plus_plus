// https://leetcode.com/problems/target-sum/
#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return findWays(n - 1, nums, target);
    }

    // dp is bit difficult due to negative signs but if we can decode tis problem we get a subset partition technique
    int findWays(int index, vector<int> &nums, int target)
    {
        // if(index<0){
        //     if(target==0){
        //         return 1;
        //     }
        //      return 0;
        // }
        if (index == 0)
        {
            if (target == 0 && nums[0] == 0)
            {
                return 2;
            }
            if (nums[0] + target == 0 || nums[0] - target == 0)
            {
                return 1;
            }
            return 0;
        }

        // two operations can be possible
        int plus = findWays(index - 1, nums, target + nums[index]);
        int minus = minus = findWays(index - 1, nums, target - nums[index]);
        return plus + minus;
    }
};