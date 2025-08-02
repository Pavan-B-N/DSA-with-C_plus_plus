// https://leetcode.com/problems/non-overlapping-intervals//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // we need to remove the largest interval whhich overalps
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;

        // Step 1: Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int count = 0;                  // Count of intervals to remove
        int prev_end = intervals[0][1]; // End of the last non-overlapping interval

        // Step 2: Iterate from the second interval onward
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < prev_end)
            {
                // Overlap → remove current interval
                count++;
            }
            else
            {
                // No overlap → update prev_end
                prev_end = intervals[i][1];
            }
        }

        return count;
    }
};
