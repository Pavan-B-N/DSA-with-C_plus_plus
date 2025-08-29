// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        return countSubsets(0, nums, target, INT_MAX, INT_MIN);
    }

    int countSubsets(int index, vector<int> &nums, int target,
                     int minVal, int maxVal)
    {
        if (index == nums.size())
        {
            if (minVal == INT_MAX && maxVal == INT_MIN)
                return 0; // empty subset
            return (minVal + maxVal) <= target ? 1 : 0;
        }

        // Not pick
        int notPick = countSubsets(index + 1, nums, target, minVal, maxVal);

        // Pick
        int newMin = min(minVal, nums[index]);
        int newMax = max(maxVal, nums[index]);
        int pick = countSubsets(index + 1, nums, target, newMin, newMax);

        return pick + notPick;
    }
};

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0, right = n - 1;
        long long res = 0;

        while (left <= right)
        {
            int sum = nums[left] + nums[right];
            if (sum <= target)
            {
                res = (res + modPow(2, right - left)) % MOD;
                left++;
            }
            else
            {
                right--;
            }
        }
        return (int)res;
    }

private:
    // x^n
    //  x^21 = x.x^20
    // x^20 = x^10 . x^10 = 2X ^ 10
    long long modPow(long long x, long long n)
    {
        const int MOD = 1e9 + 7;
        long long res = 1;
        x %= MOD;
        while (n != 0)
        {
            // x^21 like n is odd
            if (n & 1)
            {
                res = (res * x) % MOD;
                n--; // optional because n/2 awlays even
            }

            x = (x * x) % MOD;
            n = n >> 1; // n/2
        }
        return res;
    }
};
