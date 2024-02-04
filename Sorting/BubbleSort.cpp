#include <iostream>
using namespace std;

void printArr(int arr[], int n);
void swap(int arr[], int i, int j);

// average = o(n)
// worst = o(n^2)
void bubbleSort(int arr[], int n)
{
    // bubble sort swap highest first
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                swap(arr, j, j+1);
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {10, 5, 2, 3, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    // print the array
    cout << "Sorted Array is : ";
    bubbleSort(arr,n);
    printArr(arr, n);

    return 0;
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}