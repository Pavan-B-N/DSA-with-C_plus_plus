// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getLIS(const vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        vector<int> dp(n, 1), prev(n, -1);

        // Fill dp[] and prev[] arrays
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }

        // Find index of the maximum LIS length
        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct LIS by backtracking
        vector<int> lis;
        for (int cur = maxIndex; cur != -1; cur = prev[cur])
        {
            lis.push_back(arr[cur]);
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};
