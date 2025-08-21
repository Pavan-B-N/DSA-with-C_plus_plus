// 0 1 1 2 3 5 8 13 21
#include <iostream>
#include <vector>
using namespace std;
// recursive solution has overlapping subproblem
// time complexity is exponential
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

// memoization technique = top-down approach
// Time complexity = o(n) left skew of tree
// Space complexity = o(n)
int fiboDPHelper(int n,vector<int> &dp);
int fiboDP(int n){
    vector<int> dp(n+1,-1);
   return fiboDPHelper(n,dp);
}
int fiboDPHelper(int n,vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]= fiboDPHelper(n-1,dp)+fiboDPHelper(n-2,dp);
}

// tabulation = bottom-up approach
// Time complexity = o(n)
// Space complexity = o(n)
int fiboTabulation(int n){
    vector<int> dptable(n+1,-1);
    dptable[0]=0;
    dptable[1]=1;
    for(int i=2;i<=n;i++){
        dptable[i]=dptable[i-1]+dptable[i-2];
    }
    return dptable[n];
}
// Time complexity = o(n)
// Space complexity = o(1)
int fiboBetter(int n){
    if(n<=1){
        return n;
    }
    int a=0;
    int b=1;
    for(int i=2;i<=n;i++){
        int res=a+b;
        a=b;
        b=res;
    }
    return b;
}


int main(int argc, char const *argv[])
{
    
    // cout<<fibo(12)<<endl;// 144
    // cout<<fiboDP(12)<<endl;
    // cout<<fiboTabulation(12)<<endl;
    cout<<fiboBetter(12)<<endl;

    return 0;
}
