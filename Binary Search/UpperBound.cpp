/*
You are given a sorted array ‘arr’ containing ‘n’ integers and an integer ‘x’.Implement the ‘upper bound’ function to find the index of the upper bound of 'x' in the array.

1. The upper bound in a sorted array is the index of the first value that is greater than a given value.
2. If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
*/
// https://www.naukri.com/code360/problems/implement-upper-bound_8165383
#include <vector>
#include <algorithm>
using namespace std;

// O(logn)
int upperBound(vector<int> &arr, int x, int n)
{
    int start = 0;
    int end = n - 1;
    int ub = n; // by default ub is n, so if no upperbound found then its n according to algorithm
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] > x)
        {
            ub = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ub;
}

int upperBound(vector<int> &arr, int x, int n)
{ // O(logn)
    return upper_bound(arr.begin(), arr.end(), x) - arr.begin();
}