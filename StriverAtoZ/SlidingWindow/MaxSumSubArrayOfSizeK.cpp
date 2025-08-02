// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
#include <vector>
using namespace std;
/*
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.
*/

// constant window pattern based problem
class Solution
{
public:
    int maximumSumSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
            return 0;

        int left = 0;
        int windowSum = 0;
        int maxSum = INT_MIN;
        // compute the sum of the firstWindow
        for (int right = 0; right < k; right++)
        {
            windowSum += arr[right];
        }
        maxSum = max(maxSum, windowSum);

        for (int right = k; right < n; right++)
        {
            windowSum -= arr[left++];
            windowSum += arr[right];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};