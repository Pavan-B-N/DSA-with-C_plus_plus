// find ceiling of a given number - binary search

// arr=[2,3,5,9,14,16,18]
// ceiling of 14 = 14
// ceiling of 15 = 16
// ceiling means smallest element in the given array that is greater than or equal to the target number

// since the given array is sorted , hence we can apply binary search so that start->ceil and end->floor

#include <iostream>
using namespace std;

// https://leetcode.com/problems/search-insert-position/description/
// ceil is also known as lower bound
// start = ceil or lower_bound
// end = floor
int ceilNum(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return arr[mid];
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return arr[start];
}
// end->floor
int floorNum(int arr[], int len, int target)
{
    int start = 0;
    int end = len - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return arr[mid];
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return arr[end];
}