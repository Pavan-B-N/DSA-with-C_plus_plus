// https://www.geeksforgeeks.org/problems/implement-upper-bound/1
#include <vector>
using namespace std;
// The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.
class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        // upperBound > target
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] > target)
            {
                // ans = mid
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start; // or ans
    }
};
