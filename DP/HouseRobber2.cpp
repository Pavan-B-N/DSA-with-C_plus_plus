// https://www.naukri.com/code360/problems/house-robber_839733
/*
Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

2 3 2 = 3
1 3 2 1 = 4
*/
#include <iostream>
#include <vector>
using namespace std;
// recursive solution
int maxMoneyCanRobRecursive(vector<int>& valueInHouse, int index, bool robRight) {
    if (index < 0) return 0;
    if (index == 0 && robRight) return 0;
    if (index == 0) return valueInHouse[index];

    // Recursive cases: Choose to rob or skip the current house
    int pick = valueInHouse[index] + maxMoneyCanRobRecursive(valueInHouse, index - 2, robRight);
    int notPick = maxMoneyCanRobRecursive(valueInHouse, index - 1, robRight);

    return max(pick, notPick);
}

long long int houseRobberRecursive(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0]; // Single house case
    // Exclude the last house
    int excludeLast = maxMoneyCanRobRecursive(valueInHouse, n - 2, false);
    // Exclude the first house
    int excludeFirst = maxMoneyCanRobRecursive(valueInHouse, n - 1, true);

    return max(excludeLast, excludeFirst);
}

// DP = memoization
int maxMoneyCanRobDP(vector<int>& valueInHouse, int index, bool robRight,vector<int> &dp) {
    if (index < 0) return 0;
    if (index == 0 && robRight) return 0;
    if (index == 0) return valueInHouse[index];
    if(dp[index]!=-1){
        return dp[index];
    }
    // Recursive cases: Choose to rob or skip the current house
    int pick = valueInHouse[index] + maxMoneyCanRobDP(valueInHouse, index - 2, robRight,dp);
    int notPick = maxMoneyCanRobDP(valueInHouse, index - 1, robRight,dp);

    return dp[index]=max(pick, notPick);
}
long long int houseRobberDP(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0]; // Single house case
    // Exclude the last house
    vector<int> dp1(n, -1);
    int excludeLast = maxMoneyCanRobDP(valueInHouse, n - 2, false,dp1);
    // Exclude the first house
    vector<int> dp2(n, -1);
    int excludeFirst = maxMoneyCanRobDP(valueInHouse, n - 1, true,dp2);

    return max(excludeLast, excludeFirst);
}

// tabulation - best solution
int maxMoneyCanRob(vector<int>& valueInHouse, int start, int end) {
    int prev2 = 0, prev1 = 0;
    for (int i = start; i <= end; ++i) {
        int pick = valueInHouse[i] + prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];

    // Rob houses excluding the first or the last house
    int excludeFirst = maxMoneyCanRob(valueInHouse, 1, n - 1);
    int excludeLast = maxMoneyCanRob(valueInHouse, 0, n - 2);

    return max(excludeFirst, excludeLast);
}

int main(int argc, char const *argv[])
{
    cout<<"House Robber 2"<<endl;
    return 0;
}
