// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;
// array contains only +ve numbers
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int totalSum = 0;
    for (auto ele : arr)
    {
        totalSum += ele;
    }
    int target = totalSum;

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // SubsetSumEqualsToK
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (n > 0 && arr[0] <= target)
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

    int mini = 1e9;
    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (dp[n - 1][s1])
        {
            int s2 = (totalSum - s1);
            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}
