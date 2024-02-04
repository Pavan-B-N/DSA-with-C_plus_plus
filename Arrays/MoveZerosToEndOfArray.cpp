// given an array containing zeros move zeros to end of an array
// arr[]={0,1,0,4,12};
// output=[1,4,12,0,0]
#include <iostream>
using namespace std;

void moveZerosToEnd(int arr[], int n)
{
    int k = 0; // array pointer
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[k++] = arr[i];
        }
    }
    // rest of the elemnets must be overridden to zero
    while (k < n)
    {
        arr[k++] = 0;
    }
}

int main()
{
    int arr[] = {0, 1, 0, 4, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZerosToEnd(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}