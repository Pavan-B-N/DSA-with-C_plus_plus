// cyclic sort is applied when array elemnets is in 1-n;
// duplicates are not allowed
// Time complexity is o(n)
#include <iostream>
#include <algorithm>
using namespace std;

void cyclicSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        while (i != arr[i]-1)
        {
            // duplicates are not allowed
            if (arr[i] == arr[arr[i] - 1])
            {
                break;
            }
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cyclicSort(arr, n);
    printArr(arr, n);

    return 0;
}