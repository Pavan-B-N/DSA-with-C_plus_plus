/*
Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).

*/
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
class Solution
{
public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr)
    {
        // Your Code Here
        int inversions = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    inversions++;
                }
            }
        }
        return inversions;
    }
};

// O(nlogn)
class Solution
{
public:
    int inversionCount(vector<int> &arr)
    {
        int invc = 0;
        int n = arr.size();
        mergeSort(arr, 0, n - 1, invc);
        return invc;
    }

    void mergeSort(vector<int> &arr, int low, int high, int &inv)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid, inv);
            mergeSort(arr, mid + 1, high, inv);
            merge(arr, low, mid, high, inv);
        }
    }

    void merge(vector<int> &arr, int low, int mid, int high, int &inv)
    {
        vector<int> res(high - low + 1);
        int i = low;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                res[k++] = arr[i++];
            }
            else
            {
                // arr[i] > arr[j]
                // if arr[i]>arr[j] then all the elements from i to mid are sorted or increasing so they also greater than arr[j]
                inv += (mid - i) + 1;
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
};