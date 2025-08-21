// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        if (n == 0)
            return 0;

        vector<int> lis(n, 1), lds(n, 1);

        // LIS ending at i
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    lis[i] = max(lis[i], lis[j] + 1);

        // LDS starting at i
        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j > i; --j)
                if (nums[j] < nums[i])
                    lds[i] = max(lds[i], lds[j] + 1);

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            // Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence
            if (lis[i] > 1 && lds[i] > 1)            // must have both sides
                ans = max(ans, lis[i] + lds[i] - 1); // peak counted twice
        }
        return ans; // 0 if no valid bitonic subsequence
    }
};
