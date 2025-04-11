/*
Largest Sum Contiguous Subarray (Kadane’s Algorithm)
Kadane’s Algorithm takes o(n) time complexity
*/

#include <iostream>
#include <climits>
using namespace std;
// o(n) = kadane's algorithm
int maxSubArraySum(int a[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

// o(n^2)
int maxSumSubArray(int arr[],int n){
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);
 
    int max_sum = maxSubArraySum(a, n);
    // int max_sum = maxSumSubArray(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}