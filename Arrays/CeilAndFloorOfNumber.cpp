// find ceiling of a given number - binary search

// arr=[2,3,5,9,14,16,18]
// ceiling of 14 = 14
// ceiling of 15 = 16
// ceiling means smallest element in the given array that is greater than or equal to the target number

// since the given array is sorted , hence we can apply binary search so that start->ceil and end->floor

#include <iostream>
using namespace std;

// works for both sorted and unsorted array
int ceil_num(int arr[], int len, int target)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= target)
        {
            return arr[i];
        }
    }
    return -1;
}

// if array is sorted then we can use binary search
// since the given array is sorted , hence we can apply binary search so that start->ceil and end->floor
int ceilNum(int arr[], int len, int target)
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

int main()
{
    int arr[] = {2, 3, 5, 9, 14, 16, 18};
    int target = 15;
    int len = sizeof(arr) / sizeof(arr[0]);
    int res = ceil_num(arr, len, target);
    cout << res << endl;
    res = ceilNum(arr, len, target);
    cout << res << endl;
    res = floorNum(arr, len, target);
    cout << res << endl;
}