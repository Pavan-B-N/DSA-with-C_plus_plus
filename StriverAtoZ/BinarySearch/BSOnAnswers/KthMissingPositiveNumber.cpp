// https://leetcode.com/problems/kth-missing-positive-number/description/
/*
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        // edge case
        // arr = [10,12,14,...]
        // k = 1,2,8,9, missingNumbers == k
        if (k < arr[0])
        {
            return k;
        }

        int index = findFloorIdxForMissingK(arr, k);
        int expectedNumber = index + 1;
        int missingCount = arr[index] - expectedNumber;
        int m = k - missingCount;
        return arr[index] + m;
    }

    int findFloorIdxForMissingK(vector<int> &arr, int k)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int expectedNumber = mid + 1;
            int missingCount = arr[mid] - expectedNumber;
            if (missingCount < k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return end;
    }
};