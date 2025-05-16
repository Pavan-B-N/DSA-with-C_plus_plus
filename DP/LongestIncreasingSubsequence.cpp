// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getLIS(n - 1, -1, nums, dp);
    }

    int getLIS(int index, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (index < 0) return 0;

        // prev+1 = prev, because by default prev is -1 so to handle this we are using shift index method
        if (dp[index][prev + 1] != -1) return dp[index][prev + 1];

        int notPick = getLIS(index - 1, prev, nums, dp);

        int pick = 0;
        if (prev == -1 || nums[index] < nums[prev]) {
            pick = 1 + getLIS(index - 1, index, nums, dp);
        }

        return dp[index][prev + 1] = max(pick, notPick);
    }
};
