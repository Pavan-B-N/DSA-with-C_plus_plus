/*
You are given an array 'arr' sorted in non-decreasing order and a number 'x'. You must return the index of the lower bound of 'x'.

'lower_bound' of a number 'x' is defined as the smallest number such that the value 'arr[idx]' is not less than 'x'


value >= x

*/

// https://www.naukri.com/code360/problems/lower-bound_8165382?leftPanelTabValue=PROBLEM

#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x)
{
    int start = 0;
    int end = n - 1;

    int lb = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // we no duplicates we could have simply returned mid as lower bound
        // but if arr contains duplicates then we need to find the first match index such that its value is the smallest, index >= x
        if (arr[mid] >= x)
        {
            lb = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return lb;
}

// std::lower_bound() returns an iterator.
// Dereferencing it (*it) gives the value at that position.
// Subtracting the iterator from arr.begin() gives the index.

//  Return the index (most commonly used)
int lowerBound(vector<int> arr, int n, int x)
{
    return lower_bound(arr.begin(), arr.end(), x) - arr.begin(); // returns index
}

// Return the value at the lower bound
int lowerBoundValue(vector<int> arr, int n, int x)
{
    auto it = lower_bound(arr.begin(), arr.end(), x);
    if (it != arr.end())
        return *it; // value at lower bound
    return -1;      // or any sentinel value if no such element found
}
