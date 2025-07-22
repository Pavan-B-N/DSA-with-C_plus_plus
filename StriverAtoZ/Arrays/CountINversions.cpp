// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
/*
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/
#include <vector>
using namespace std;
// tag: [favorite]

class Solution
{
public:
    int inversionCount(vector<int> &arr)
    {
        int count = 0;
        int n = arr.size();
        mergeSort(0, n - 1, arr, count);
        return count;
    }
    void mergeSort(int low, int high, vector<int> &arr, int &count)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            mergeSort(low, mid, arr, count);
            mergeSort(mid + 1, high, arr, count);
            merge(low, mid, high, arr, count);
        }
    }
    void merge(int low, int mid, int high, vector<int> &arr, int &count)
    {
        int i = low;
        int j = mid + 1;
        vector<int> res;
        while (i <= mid && j <= high)
        {
            if (arr[i] > arr[j])
            {
                count += (mid - i + 1); // inversion count
                res.push_back(arr[j]);
                j++;
            }
            else
            {
                res.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid)
        {
            res.push_back(arr[i]);
            i++;
        }

        while (j <= high)
        {
            res.push_back(arr[j]);
            j++;
        }

        // replace or write back
        for (int k = 0; k < res.size(); k++)
        {
            arr[k + low] = res[k];
        }
    }
};