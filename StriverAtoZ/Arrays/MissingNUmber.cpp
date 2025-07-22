// https://leetcode.com/problems/missing-number/description/
/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/
#include <vector>
#include <numeric>
using namespace std;

// Time Complexity: O(n)
class Solution
{
public:
    // maths
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int actualSum = (n * (n + 1)) / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return actualSum - sum;
    }
};

// Time Complexity: O(n)
class Solution
{
public:
    // cyclic sort
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] < n && i != nums[i])
            {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i != nums[i])
            {
                return i;
            }
        }
        return n;
    }
};

// Time Complexity: O(n)
class Solution
{
public:
    // Bit manipulation
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xorVal = n;

        for (int i = 0; i < n; ++i)
        {
            xorVal ^= i ^ nums[i];
        }

        return xorVal;
    }
};
