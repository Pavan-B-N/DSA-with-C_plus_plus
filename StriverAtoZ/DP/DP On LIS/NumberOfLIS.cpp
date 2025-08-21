// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> lengths(n, 1), counts(n, 1);
        int maxLen = 0, total = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    if (lengths[j] + 1 > lengths[i])
                    {
                        lengths[i] = lengths[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if (lengths[j] + 1 == lengths[i])
                    {
                        counts[i] += counts[j];
                    }
                }
            }
            if (lengths[i] > maxLen)
            {
                maxLen = lengths[i];
                total = counts[i];
            }
            else if (lengths[i] == maxLen)
            {
                total += counts[i];
            }
        }

        return total;
    }
};
