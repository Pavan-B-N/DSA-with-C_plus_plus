
// given an array of range 1-n , find the missing numbers in the array
// google question
/*
  int[] arr = { 4, 3, 2, 7, 8, 2, 3, 1 };// 8
// output - [5,6]
*/
// https://leetcode.com/problems/missing-number/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        cyclicSort(nums, nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                return i + 1;
            }
        }

        return 0;
    }

    void cyclicSort(vector<int> &arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            while (i != arr[i] - 1)
            {
                // skip duplicates
                if (arr[i] == 0 || arr[i] == arr[arr[i] - 1])
                {
                    break;
                }
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
    }
};

// maths
int missingNumber(vector<int> &nums)
{
    int totalsum = 0;
    for (auto &ele : nums)
    {
        totalsum += ele;
    }
    int n = nums.size();
    int actualSum = (n * (n + 1)) / 2;
    return actualSum - totalsum;
}