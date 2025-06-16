// search in bitonic array
#include <iostream>
using namespace std;

// asc = 1,2,3,4,5
// desc = 5,4,3,2,1
int orderAgnosticBinarySearch(int arr[], int n, int start, int end, int target)
{
    int asc = arr[start] < arr[end] ? 1 : 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (asc)
        {
            if (arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] > target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int findPeak(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    // return start or end
    return end;
}

// logn
int search(int arr[], int n, int target)
{
    int peakIndex = findPeak(arr,n); 
    // search in ascending order sorted array
    int index = orderAgnosticBinarySearch(arr,n,0,peakIndex,target);
    // if target not found in ascending order part search in descending order part
    if (index == -1)
    {
        index = orderAgnosticBinarySearch(arr,n,peakIndex+1,n-1,target);
    }
    return index;
}

int main()
{
    int arr[] = {1,3,5,7,5,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=7;
    int res=search(arr,n,target);
    cout<<res<<endl;
    return 0;
}