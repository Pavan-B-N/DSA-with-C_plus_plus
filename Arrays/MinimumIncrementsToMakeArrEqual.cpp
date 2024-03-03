/*
Minimum increment by k operations to make all elements equal

You are given an array of n-elements, you have to find the number of operations needed to make all elements of array equal. Where a single operation can increment an element by k. If it is not possible to make all elements equal print -1.

Input : arr[] = {4, 7, 19, 16},  k = 3
Output : 10

Input : arr[] = {4, 4, 4, 4}, k = 3
Output : 0

Input : arr[] = {4, 2, 6, 8}, k = 3
Output : -1

*/
#include <iostream>
#include <algorithm>
using namespace std;

int minOps(int arr[], int n, int k)
{
    // max elements of array
    // max_element returns the address of the array elemen so we need to make dereference to it-
    int max = *max_element(arr, arr+n);
    int res = 0;
 
    for (int i = 0; i < n; i++) {
        if ((max - arr[i]) % k != 0)
            return -1;
         else
            res += (max - arr[i]) / k;
    }
 
    // return result
    return res;
}