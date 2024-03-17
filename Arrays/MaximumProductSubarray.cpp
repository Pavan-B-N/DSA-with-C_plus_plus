/*
Maximum Product Subarray using Kadane's Algorithm   

Given an array that contains both positive and negative integers, the task is to find the product of the maximum product subarray. 

Input: arr[] = {6, -3, -10, 0, 2}
Output:  180
Explanation: The subarray is {6, -3, -10}
*/

#include <iostream>
#include <climits>
using namespace std;

// o(n^2)
int maxSubarrayProduct2(int arr[], int n)
{
    // Initializing result
    int result = INT_MIN;
 
    for (int i = 0; i < n; i++) {
        int mul = 1;
        // traversing in current subarray
        for (int j = i; j < n; j++) {
            mul *= arr[j];
            result = max(result, mul);
        }
    }
    return result;
}

// o(n) = kadanes algorithm
long long maxSubarrayProduct(int arr[], int n) {
    if (n == 0) {
        return 0; // If the array is empty, return 0
    }

    // max positive product ending at the current position
    long long max_ending_here = arr[0];

    // min negative product ending at the current position
    long long min_ending_here = arr[0];

    // Initialize overall max product
    long long max_so_far = arr[0];

    /* Traverse through the array.
    The maximum product subarray ending at an index
    will be the maximum of the element itself,
    the product of element and max product ending previously,
    and the min product ending previously. */
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            swap(max_ending_here, min_ending_here); // Swap max and min if current element is negative
        }
        max_ending_here = max((long long)arr[i], max_ending_here * arr[i]);
        min_ending_here = min((long long)arr[i], min_ending_here * arr[i]);

        // Update the maximum product so far
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

// Driver code
int main() {
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Subarray product is " << maxSubarrayProduct(arr, n);
    return 0;
}
