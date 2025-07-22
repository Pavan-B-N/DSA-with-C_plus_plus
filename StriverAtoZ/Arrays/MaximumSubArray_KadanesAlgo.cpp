// https://leetcode.com/problems/maximum-subarray/
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // kadane's Algorithm
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            // reset or start new SumArray
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum;
    }
};