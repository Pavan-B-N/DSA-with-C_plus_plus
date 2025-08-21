// https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628?leftPanelTabValue=PROBLEM
// Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences

#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

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

int countSubsets(vector<int> &arr, int target, int index, vector<vector<int>> &dp)
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

    return dp[index][target] = (pick + notPick) % MOD;
}

