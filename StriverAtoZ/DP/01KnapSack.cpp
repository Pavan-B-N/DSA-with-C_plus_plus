// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// https://www.naukri.com/code360/problems/0-1-knapsack_920542?leftPanelTabValue=SUBMISSION
/*
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized.

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
*/

#include <vector>
using namespace std;

class Solutionz
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return getMaxValue(n - 1, W, val, wt, dp);
    }

    int getMaxValue(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        // this works but index==0, will be best for building intution for tabulation technique
        // if(index<0){
        //     return 0;
        // }

        // so try to think the base condition with single element always
        if (index == 0)
        {
            if (W >= wt[0])
            {
                return val[0];
            }
            return 0;
        }

        if (dp[index][W] != -1)
        {
            return dp[index][W];
        }
        // notPick
        int notPick = getMaxValue(index - 1, W, val, wt, dp);
        // pick
        int pick = INT_MIN;
        if (W >= wt[index])
        {
            pick = val[index] + getMaxValue(index - 1, W - wt[index], val, wt, dp);
        }

        return dp[index][W] = max(pick, notPick);
    }
};

// tabulation
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    // code here
    int n = val.size();
    if (n < 1)
    {
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int currWeight = 0; currWeight <= W; currWeight++)
    {
        if (currWeight >= wt[0])
        {
            dp[0][currWeight] = val[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int currWeight = 0; currWeight <= W; currWeight++)
        {
            // notPick
            int notPick = dp[index - 1][currWeight];
            // pick
            int pick = INT_MIN;
            if (currWeight >= wt[index])
            {
                pick = val[index] + dp[index - 1][currWeight - wt[index]];
            }

            dp[index][currWeight] = max(pick, notPick);
        }
    }

    return dp[n - 1][W];
}
