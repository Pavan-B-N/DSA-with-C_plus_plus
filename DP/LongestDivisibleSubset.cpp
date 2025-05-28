// https://leetcode.com/problems/largest-divisible-subset/
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> subset;
        vector<int> ans;
        // if array is sorted then, we can just check if last ele is divisible by number so all of them are divisible
        sort(nums.begin(), nums.end());
        LDS(nums.size() - 1, nums, subset, ans);
        return ans;
    }

    // TLE
    void LDS(int index, vector<int> &nums, vector<int> &subset, vector<int> &ans)
    {
        if (index < 0)
        {
            if (subset.size() > ans.size())
            {
                ans = subset;
            }
            return;
        }

        // notPick
        LDS(index - 1, nums, subset, ans);

        // pick
        if (subset.empty() || subset.back() % nums[index] == 0 ||
            nums[index] % subset.back() == 0)
        {
            // if (checkDivisibility(subset, nums[index])) {
            subset.push_back(nums[index]);
            LDS(index - 1, nums, subset, ans);
            subset.pop_back();
        }
    }

    // optimized dp for LIS works
    // Sorting: O(n log n)
    // DP nested loop: O(n²)
    // Total: O(n²) – efficient enough for n ≤ 1000
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1); // dp[i] = length of largest subset ending at i
        int max_idx = 0;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_idx])
            {
                max_idx = i;
            }
        }

        // Reconstruct the answer
        vector<int> result;
        for (int i = max_idx; i >= 0; i = prev[i])
        {
            result.push_back(nums[i]);
            if (prev[i] == -1)
                break;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};