// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
#include <vector>
using namespace std;

//  find the index (0-based) of the smallest element in arr[] that is greater than or equal to x.
// This element is called the ceil of x. If such an element does not exist, return -1.
class Solution
{
public:
    int findCeil(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= target)
            {
                // ans
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start == n ? -1 : start; // ans
    }
};