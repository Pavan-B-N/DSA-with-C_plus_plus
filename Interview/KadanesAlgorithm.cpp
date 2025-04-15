// https://leetcode.com/problems/maximum-subarray/
//  MaximumSubArraySum
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// brute-force o(n^2)
void printSubArray(vector<int> &arr)
{
    vector<vector<int>> res;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> inner;
        for (int j = i; j < n; j++)
        {
            inner.push_back(arr[j]);
            res.push_back(inner);
        }
    }

    for (auto &subArray : res)
    {
        cout << "[ ";
        for (auto ele : subArray)
        {
            cout << ele << " ,";
        }
        cout << " ] " << endl;
    }

    cout << "Total formed SubsArrays = " << res.size() << endl;
    cout << "Expected subArrays = " << (n * (n + 1)) / 2 << endl;
}

// brute-force o(n^2)
int maxSumSubArray(vector<int> &arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

// kadane's Algorithm =  o(n)

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

int main()
{
    vector<int> arr = {-9, -7, 8, 2, 5, -10};

    cout << maxSumSubArray(arr);
}