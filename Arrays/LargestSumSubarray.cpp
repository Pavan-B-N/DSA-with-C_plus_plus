/*
Largest Sum Contiguous Subarray (Kadane’s Algorithm)
Kadane’s Algorithm takes o(n) time complexity
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// o(n) = kadane's algorithm
int maxSubArray(vector<int>& nums) {
    // kadane's Algorithm
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<nums.size();i++){
        currSum+=nums[i];
        maxSum=max(currSum,maxSum);
        // reset or start new SumArray
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
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
