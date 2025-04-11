/*
Frog Jump With K Distance

allowed to jump i+1,i+2,i+3 .... i+k
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Recursive Solution with Memoization
int frogJumpKDistanceRec(int n, vector<int> &heights, int k, int index, vector<int> &dp) {
    if (index == 0) return 0; // Base case: starting point
    if (dp[index] != -1) return dp[index]; // Return memoized result if available

    int min_energy = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (index - j >= 0) {
            int energy = frogJumpKDistanceRec(n, heights, k, index - j, dp) + abs(heights[index] - heights[index - j]);
            min_energy = min(min_energy, energy);
        }
    }

    return dp[index] = min_energy; // Memoize and return the result
}

int frogJumpKDistance(int n, vector<int> &heights, int k) {
    vector<int> dp(n, -1);
    return frogJumpKDistanceRec(n, heights, k, n - 1, dp);
}


// Tabulation Approach
int frogJumpKDistance(int n, vector<int> &heights, int k) {
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
    }
    return dp[n - 1];
}

// Optimized Space Approach;
// but if k==n then space is not optimized
int frogJumpKDistanceOptimized(int n, vector<int> &heights, int k) {
    vector<int> dp(k + 1, 0);

    for (int i = 1; i < n; i++) {
        int min_energy = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                min_energy = min(min_energy, dp[(i - j) % (k + 1)] + abs(heights[i] - heights[i - j]));
            }
        }
        dp[i % (k + 1)] = min_energy;
    }
    return dp[(n - 1) % (k + 1)];
}

int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int n = heights.size();
    int k = 3;
    cout << "Minimum energy lost: " << frogJumpKDistance(n, heights, k) << endl;
    return 0;
}
