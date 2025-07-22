// https://www.geeksforgeeks.org/problems/rotation4723/1
#include <vector>
using namespace std;

class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int pivotIndex = findPivot(arr);
        return pivotIndex + 1;
    }
    int findPivot(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid + 1 < n && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[start] > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};
