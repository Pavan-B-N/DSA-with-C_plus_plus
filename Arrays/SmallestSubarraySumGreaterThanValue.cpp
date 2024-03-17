/*
Given an array arr[] of integers and a number x, the task is to find the smallest subarray with a sum greater than or equal to  the given value

arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

*/

// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time Complexity: O(n2).
int minSubArrayLen(int x, vector<int> &arr)
{
    int n = arr.size();
    int min_len = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;

        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];

            if (curr_sum >= x)
            {
                min_len = min(min_len, j - i + 1);
                break;
            }
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}

// o(n) using two pointer method
int minSubArrayLen2(int x, vector<int> &arr)
{
    int n = arr.size();
    int min_len = INT_MAX;
    int curr_sum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end)
    {
        curr_sum += arr[end];

        while (curr_sum >= x)
        {
            min_len = min(min_len, end - start + 1);
            curr_sum -= arr[start];
            ++start;
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}