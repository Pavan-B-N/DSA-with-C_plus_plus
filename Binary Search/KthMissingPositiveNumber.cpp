// https://leetcode.com/problems/kth-missing-positive-number/description/
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
        if (n >= 1 && k < arr[0])
        {
            return k;
        }

        int start = findIndexOfFloorOfMissing(arr, k);

        int expectedNumber = start + 1;
        int missingNumbers = arr[start] - expectedNumber;
        // return arr[start] + (k - missingNumbers);
        return k + start + 1;
    }

    int findIndexOfFloorOfMissing(vector<int> &arr, int k)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int expectedNumber = mid + 1;
            int missingNumbers = arr[mid] - expectedNumber;
            if (missingNumbers < k)
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