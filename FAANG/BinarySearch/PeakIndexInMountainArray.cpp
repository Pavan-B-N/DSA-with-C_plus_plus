// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return end;
    }
};