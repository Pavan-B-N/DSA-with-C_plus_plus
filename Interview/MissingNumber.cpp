// given an unsorted array nums,return the smallest positive integer
// you must implement an algorithm that runs in o(n) time and uses constant extra space
// nums=[1,2,0] output=3
// nums=[3,4,-1,1] output=2

// ignore the elements that are -ve and greater than n

#include <iostream>
#include <algorithm>
using namespace std;

void cyclicsort(int arr[], int n)
{
    for (int index = 0; index < n; index++)
    {
        while (index != arr[index] - 1)
        {
            // duplicates are not allowed
            if (arr[index] <= 0 || arr[index] > n || arr[index] == arr[arr[index] - 1])
            {
                break;
            }
            swap(arr[index], arr[arr[index] - 1]);
        }
    }
}

int missingNumberByCS(int arr[], int n)
{
    cyclicsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (i != arr[i] - 1)
        {
            return i + 1;
        }
    }
    return -1;
}
int missingNUmberByMaths(int arr[],int n)
{
    int actualSum = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // missing number can also be represented as zero
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
    }
    return actualSum - sum;
}

int main()
{
    // int arr[]={1,2,0};
    int arr[] = {3, 4, -1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    int res = missingNumberByCS(arr, n);
    cout << res << endl;
}