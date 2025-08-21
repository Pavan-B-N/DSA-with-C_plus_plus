// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=PROBLEM
/*
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
*/
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// Partition Set Into 2 Subsets With Min Absolute Sum Diff
// array contains only +ve numbers
class Solution
{

    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        subsetSumToK(n, target, arr, dp);


        for (int s1 = target; s1 >= 0; s1--)
        {
            if (dp[n - 1][s1])
            {
                int s2 = totalSum - s1;
                return abs(s1 - s2);
            }
        }
        return -1;
    }

    bool subsetSumToK(int n, int target, vector<int> &arr,
                      vector<vector<bool>> &dp)
    {

        // if(target == 0) return true;
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (arr[0] <= target)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int k = 0; k <= target; k++)
            {
                bool notpick = dp[i - 1][k];
                bool pick = false;
                if (arr[i] <= k)
                {
                    pick = dp[i - 1][k - arr[i]];
                }
                dp[i][k] = pick || notpick;
            }
        }

        return dp[n - 1][target];
    }
};
