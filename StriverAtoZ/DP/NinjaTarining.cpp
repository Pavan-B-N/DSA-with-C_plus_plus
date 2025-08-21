// https://www.naukri.com/code360/problems/ninja-s-training_3621003
#include <climits>
#include <vector>
using namespace std;

// memoization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return ninjaTraining(n - 1, points, -1, dp);
}

int ninjaTraining(int n, vector<vector<int>> &points, int prev, vector<vector<int>> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    int maxPoints = INT_MIN;

    for (int task = 0; task < 3; task++)
    {
        if (task != prev)
        {
            if (dp[n][task] == -1)
            {
                dp[n][task] = points[n][task] + ninjaTraining(n - 1, points, task, dp);
            }
            maxPoints = max(maxPoints, dp[n][task]);
        }
    }

    return maxPoints;
}

// tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Base case: day 0
    for (int task = 0; task < 3; ++task)
    {
        dp[0][task] = points[0][task];
    }

    for (int day = 1; day < n; ++day)
    {
        for (int task = 0; task < 3; ++task)
        {
            int maxMerit = 0;
            for (int last = 0; last < 3; ++last)
            {
                if (last != task)
                {
                    maxMerit = max(maxMerit, dp[day - 1][last]);
                }
            }
            dp[day][task] = points[day][task] + maxMerit;
        }
    }

    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
