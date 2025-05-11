// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM

#include <vector>
using namespace std;

int helper(int i,vector<int>& arr, int target,vector<vector<int>> &dp);
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	// if i am at index n and target=k, then dp helps us to find how many subsets can i form from 0-n, with target k
	vector<vector<int>> dp(n,vector<int>(k+1,-1));

	return helper(n-1,arr,k,dp);
}

int helper(int i,vector<int>& arr, int target,vector<vector<int>> &dp){
	// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.
	// Specified in the test case
	int mod = 1e9 + 7;
	if(i<0){
		if (target == 0) return 1;
		return 0;
	}

	if(dp[i][target]!=-1){
		return dp[i][target];
	}

	int notPick=helper(i-1,arr,target,dp);
	int pick=0;
	if(target>=arr[i]){
		pick=helper(i-1,arr,target-arr[i],dp);
	}

	return dp[i][target]=(pick+notPick) % mod;;
}