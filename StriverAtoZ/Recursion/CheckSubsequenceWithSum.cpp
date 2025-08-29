// https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        return check(0, arr, k);
    }
    bool check(int index, vector<int> &arr, int target)
    {
        if (target == 0)
            return true;
        if (index == arr.size())
            return false;

        bool notPick = check(index + 1, arr, target);
        if (notPick)
            return true;

        bool pick = false;
        if (target >= arr[index])
        {
            pick = check(index + 1, arr, target - arr[index]);
        }
        return pick || notPick;
    }
};

class Solution
{
public:
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return check(0, arr, k, dp);
    }

    bool check(int index, vector<int> &arr, int target,
               vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (index == arr.size())
            return false;
        if (dp[index][target] != -1)
            return dp[index][target];

        bool notPick = check(index + 1, arr, target, dp);
        if (notPick)
            return true;

        bool pick = false;
        if (target >= arr[index])
        {
            pick = check(index + 1, arr, target - arr[index], dp);
        }
        return dp[index][target] = pick || notPick;
    }
};

class Solution
{
public:
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

        // base case: target = 0 is always achievable
        for (int index = 0; index <= n; index++)
        {
            dp[index][0] = true;
        }

        // fill from bottom up
        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= k; target++)
            {
                bool notPick = dp[index + 1][target];
                bool pick = false;

                if (target >= arr[index])
                {
                    pick = dp[index + 1][target - arr[index]];
                }
                dp[index][target] = pick || notPick;
            }
        }

        return dp[0][k];
    }
};
