/*
Given an array of integers, rearrange the array such that the elements at even positions (0-based indexing) are greater than the elements at odd positions.

Input: [1, 2, 3, 4, 5, 6, 7, 8]
Output: [2, 1, 4, 3, 6, 5, 8, 7]
Explanation: 
After rearranging the array, the elements at even positions (0, 2, 4, 6) are greater than the elements at odd positions (1, 3, 5, 7).

*/
// Wave form of an array
#include <iostream>
#include <algorithm>
using namespace std;
// Time Complexity: O(n * log n)
// Auxiliary Space: O(1)
void reArrage(int arr[],int n){
    //sort the array
    sort(arr,arr+n);

    for(int i=0;i<n-1;i+=2){
        swap(arr[i],arr[i+1]);
    }

    // Print result
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(A) / sizeof(A[0]);
    reArrage(A, n);
    return 0;
}