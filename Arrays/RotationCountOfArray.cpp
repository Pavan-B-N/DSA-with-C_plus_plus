#include <iostream>
using namespace std;

int pivot(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid > start && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        if (arr[start] >= arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1; // Indicates no pivot found
}

int rotationsCount(int arr[], int n)
{
    int p = pivot(arr, n);
    cout << "Pivot value: " << arr[p] << " at index: " << p << endl;
    return p + 1;
}

int main()
{
    int arr[] = {10, 12, 2, 4, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = rotationsCount(arr, n);
    cout << "Rotation Count = " << res << endl;
    return 0;
}
