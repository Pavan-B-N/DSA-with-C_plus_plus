/*
https://www.naukri.com/code360/problems/frog-jump_3621012

There is a frog on the '1st' step of an 'N' stairs long staircase.
The frog wants to reach the 'Nth' stair.
'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ).
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Note: 'HEIGHT[i]' is the height of the '(i+1)th' stair

// memoization technique = top-down approach
// Time complexity = o(n) left skew of tree
// Space complexity = o(n)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return frogDp(n - 1, heights, dp);
}

int frogDp(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int step1 = frogDp(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int step2 = INT_MAX;
    if (index > 1)
    {
        step2 = frogDp(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    }
    return dp[index] = min(step1, step2);
}

// Time complexity = o(n)
// Space complexity = o(n)
int frogJump(int n, vector<int> &heights)
{
    if (n <= 0)
    {
        return 0;
    }
    vector<int> dp(n, 0);
    // 'HEIGHT[i]' is the height of the '(i+1)th' stair
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
        {
            ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(fs, ss);
    }
    return dp[n - 1];
}

// Time complexity = o(n)
// Space complexity = o(1)
int frogJumpTabulation2(int n, vector<int> &heights)
{
    if (n == 1)
        return 0; // If there's only one stone, no cost is needed to stay on it

    int a = 0;                            // Cost to reach the first stone
    int b = abs(heights[1] - heights[0]); // Cost to reach the second stone from the first one

    for (int i = 2; i < n; i++)
    {
        int fs = b + abs(heights[i] - heights[i - 1]); // Cost for a single jump
        int ss = a + abs(heights[i] - heights[i - 2]); // Cost for a double jump
        int curr = min(fs, ss);                        // Minimum cost to reach the current stone
        a = b;                                         // Update the cost of the previous stone
        b = curr;                                      // Update the cost of the current stone
    }
    return b; // The minimum cost to reach the last stone
}

int main()
{
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(n, heights);
    return 0;
}
