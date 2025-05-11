// Maximum Sum of Non-Adjacent Elements | House Robber
// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
/*
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

1 2 4 = maximum sum of non-adjacent element is 5 (1+4)
2 1 4 9 = maximum sum of non-adjacent elements is 11 (2+9)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// exponential
int maxSumOfNonAdjacentElements(vector<int> &arr,int index){
    if(index==0){
        return arr[index];
    }
    if(index<0){
        return 0;
    }
    // subsequence problem method
    int pick=arr[index]+maxSumOfNonAdjacentElements(arr,index-2);
    int notPick=0+maxSumOfNonAdjacentElements(arr,index-1);
    int maxSum=max(pick,notPick);
    return maxSum;
}

// DP, top-down , memoization
// space complexity = o(n)+o(n), dp+left skew tree
int maxSumOfNonAdjacentElementsDP(vector<int> &arr,int index,vector<int> &dp){
    if(index==0){
        return arr[index];
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int pick=arr[index]+maxSumOfNonAdjacentElementsDP(arr,index-2,dp);
    int notPick=0+maxSumOfNonAdjacentElementsDP(arr,index-1,dp);
    int maxSum=max(pick,notPick);
    dp[index]=maxSum;
    return maxSum;
}

// tabulation
// space complexity = o(n)
int maxSumOfNonAdjacentElementsTabulation(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,-1);
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int pick=arr[i];
        if(i>1){
            pick+=dp[i-2];
        }
        int notPick=0+dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[n-1];
}
// tabulation + space optimization
// space complexity = o(1)
int maxSumOfNonAdjacentElementsTabulation(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    int prev1=nums[0];
    int prev2;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1){
            pick+=prev2;
        }
        int notPick=0+prev1;
        int curr=max(pick,notPick);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(int argc, char const *argv[])
{
    vector<int> arr={2,1,4,9};
    cout<<maxSumOfNonAdjacentElements(arr,arr.size()-1);
    return 0;
}
