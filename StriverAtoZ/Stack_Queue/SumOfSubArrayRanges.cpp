// https://leetcode.com/problems/sum-of-subarray-ranges/description/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// O(N)
// Stack_Queue\SumOfSubArrayMinimums.cpp
// better code quality
class Solution {
public:
    long long getContributionSum(vector<int>& nums, bool isMax) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> s;

        // Previous Element Index
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && (
                isMax ? nums[s.top()] <= nums[i] : nums[s.top()] >= nums[i]
            )) s.pop();

            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Next Element Index
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && (
                isMax ? nums[s.top()] < nums[i] : nums[s.top()] > nums[i]
            )) s.pop();

            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            total += 1LL * nums[i] * left * right;
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        // largest - smallest
        return getContributionSum(nums, true) - getContributionSum(nums, false);
    }
};


// O(N)
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> s;

        // Sum of subarray minimums
        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
                s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && nums[s.top()] >= nums[i])
                s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sumSubArrayMinimums = 0;// smallest values sum from each subarray
        for (int i = 0; i < n; ++i)
            sumSubArrayMinimums += 1LL * nums[i] * (i - prev[i]) * (next[i] - i);

        // Reset for max
        prev.assign(n, 0);
        next.assign(n, 0);
        while (!s.empty())
            s.pop();

        // Sum of subarray maximums
        for (int i = 0; i < n; ++i)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
                s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && nums[s.top()] <= nums[i])
                s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        long long sumSubArrayMaximums = 0;// largest values sum from each subarray
        for (int i = 0; i < n; ++i)
            sumSubArrayMaximums += 1LL * nums[i] * (i - prev[i]) * (next[i] - i);

        return sumSubArrayMaximums - sumSubArrayMinimums;
    }
};
