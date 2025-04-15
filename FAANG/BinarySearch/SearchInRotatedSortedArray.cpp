/*
search in rotated sorted array
Note : array doesn't contains duplicates
int arr[] = { 15, 18, 2, 3, 6, 12 };
*/
// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int> &nums, int target, int start, int end);
int findPeak(vector<int> &arr);

int search(vector<int> &nums, int target)
{
    int peak = findPeak(nums);
    int left = binary_search(nums, target, 0, peak);
    if (left == -1)
    {
        int right = binary_search(nums, target, peak + 1, nums.size() - 1);
        return right;
    }
    return left;
}
int binary_search(vector<int> &nums, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
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
int findPeak(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // edge cases are very important
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (mid - 1 > 0 && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        else if (arr[start] >= arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid; //+1
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    int target = 6;
    int i = search(arr, target);
    cout << i << endl;
}