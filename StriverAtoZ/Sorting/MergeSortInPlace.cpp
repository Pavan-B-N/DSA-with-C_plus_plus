// https://leetcode.com/problems/sort-an-array/

#include <iostream>
#include <vector>
using namespace std;
// time complexity = o(nlogn)
// avg = o(n)
vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return nums;
    }
    mergeSort(nums, 0, n - 1);
    return nums;
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // efficient way
        // we can also use l+h/2 as per algo
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> res(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            res[k++] = arr[i++];
        }
        else
        {
            res[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        res[k++] = arr[i++];
    }

    while (j <= high)
    {
        res[k++] = arr[j++];
    }

    // replace the elements
    for (int k = 0; k < res.size(); k++)
    {
        arr[low + k] = res[k];
    }
}