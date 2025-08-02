/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
*/
// https://leetcode.com/problems/non-overlapping-intervals/description/
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return 0;

        // Step 1: Sort intervals by their end time
        // to process intervals in the order they appear chronologically
        // sort based on start time: [[1, 2], [1, 5], [2, 3], [4, 6], [6, 8], [7, 9]]

        //  to pick intervals with the earliest end to allow more future intervals — a greedy choice
        // sort base on end time: [[1, 2], [2, 3], [1, 5], [4, 6], [6, 8], [7, 9]]

        //  removing the larger (wider) interval when two intervals overlap.
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
