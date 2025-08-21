// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM
#include <vector>
using namespace std;

bool helper(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[0] == target;

    if (dp[i][target] != -1)
        return dp[i][target];

    bool notPick = helper(i - 1, target, arr, dp);
    bool pick = false;
    if (arr[i] <= target)
        pick = helper(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = pick || notPick;
}

bool subsetSumToK(int n, int target, vector<int> &arr)
{
    // we cannot use boolean dp because even after computation we store false so it will not help us to identify if its computed or not
    // false = not computed or computed and false (cannot identify overlapping subproblem)
    // -1 = not computed (helps to identify overlapping subproblem )
    // 0 = computed and false
    // 1 = computed and true
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return helper(n - 1, target, arr, dp);
}

// tabulation
bool subsetSumToK(int n, int target, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // if(target == 0) return true;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // If the first element itself is less than or equal to the target, then you can form the sum equal to arr[0] using only the first element.
    // if(i == 0) return arr[0] == target;
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