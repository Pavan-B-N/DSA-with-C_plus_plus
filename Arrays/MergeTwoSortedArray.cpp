#include <iostream>
#include <algorithm>
using namespace std;

int *mergeArray(int arr1[], int arr2[], int n1, int n2)
{
    int *res;
    res = (int *)malloc((n1 + n2) * sizeof(int));
    // res=new int[n1+n2];
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            res[k++] = arr1[i++];
        }
        else
        {
            res[k++] = arr2[j++];
        }
    }
    while (i < n1)
    {
        res[k++] = arr1[i++];
    }
    while (j < n2)
    {
        res[k++] = arr2[j++];
    }
    return res;
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// o(1) extra space
// Time Complexity: O(n1 * (n2 * logN))
void mergeWithoutAuxillarySpace(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    // while loop till last element of array 1(sorted) is
    // greater than first element of array 2(sorted)
    while (arr1[n - 1] > arr2[0]) {
        if (arr1[i] > arr2[0]) {
            // swap arr1[i] with first element
            // of arr2 and sorting the updated
            // arr2(arr1 is already sorted)
            swap(arr1[i], arr2[0]);
            sort(arr2, arr2 + m);
        }
        i++;
    }
}

int main()
{
    int arr1[] = {1, 5, 6, 8};
    int arr2[] = {2, 3, 4, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // int *res = mergeArray(arr1, arr2, n1, n2);
    // // You cannot determine the size of a dynamically allocated array using sizeof
    // // You need to keep track of the size separately
    // int n3 = n1 + n2;
    // printArr(res,n3);


    mergeWithoutAuxillarySpace(arr1,arr2,n1,n2);
    printArr(arr1,n1);
    printArr(arr2,n2);

    return 0;
}
