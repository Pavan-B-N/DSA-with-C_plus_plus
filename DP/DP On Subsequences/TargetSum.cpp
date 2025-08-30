// https://leetcode.com/problems/target-sum/
#include <vector>
using namespace std;

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
        int minus = findWays(index - 1, nums, target - nums[index]);
        return plus + minus;
    }
};

// https://www.naukri.com/code360/problems/target-sum_4127362?leftPanelTabValue=SUBMISSION
/// this works only for the targets which are not negative
// i.e only in naukri but not in leetcode
/*
[1,2,3,1]
process:
[-1,+2,+3,-1]
[-1+2+3-1]=[2+3 - 1 -1] = [2+3] - [1+1] = s1-s2 = target
*/
// so they basicaly given the target which represents the diff between two sets
// hence we need to find the total subsets with the given diff
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    return countPartitionsWithGivenDifference(n, target, nums);
}
// S1 - S2 = D
// S1 + S2 = totalSum
// => 2*S1 = totalSum + D  => S1 = (totalSum + D)/2
// S2 = (totalSum - D) / 2
int countPartitionsWithGivenDifference(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int ele : arr)
        totalSum += ele;

    // Edge case: if (totalSum + d) is odd, partition not possible
    if ((totalSum + d) % 2 != 0 || totalSum < d)
        return 0;

    // S1 = (totalSum + D)/2
    int target = (totalSum + d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return countSubsets(arr, target, n - 1, dp);
}

int countSubsets(vector<int> &arr, int target, int index,
                 vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2; // pick or not pick 0
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    int notPick = countSubsets(arr, target, index - 1, dp);
    int pick = 0;
    if (target >= arr[index])
    {
        pick = countSubsets(arr, target - arr[index], index - 1, dp);
    }

    return dp[index][target] = (pick + notPick);
}
