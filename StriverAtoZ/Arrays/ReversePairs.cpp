// https://leetcode.com/problems/reverse-pairs/description/
/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
*/
#include <vector>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    int reversePairs(vector<int> &arr)
    {
        int count = 0;
        mergeSort(0, arr.size() - 1, arr, count);
        return count;
    }

    void mergeSort(int low, int high, vector<int> &arr, int &count)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergeSort(low, mid, arr, count);
            mergeSort(mid + 1, high, arr, count);
            countReversePairs(low, mid, high, arr, count); // ✅ Count before merge
            merge(low, mid, high, arr);
        }
    }

    void countReversePairs(int low, int mid, int high, vector<int> &arr, int &count)
    {
        int j = mid + 1;
        for (int i = low; i <= mid; ++i)
        {
            while (j <= high && arr[i] > 2LL * arr[j])
            {
                ++j;
            }
            count += (j - (mid + 1));
        }
    }

    void merge(int low, int mid, int high, vector<int> &arr)
    {
        vector<int> temp;
        int i = low, j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= high)
            temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); ++k)
        {
            arr[low + k] = temp[k];
        }
    }
};
