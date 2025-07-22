// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
#include <vector>
using namespace std;

class Solution
{
public:
    //   find the index (0-based) of the largest element in arr[] that is less than or equal to x.
    int findFloor(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= target)
            {
                // ans
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end; // ans
    }
};
