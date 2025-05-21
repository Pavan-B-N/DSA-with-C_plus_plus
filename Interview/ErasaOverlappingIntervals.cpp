// https://leetcode.com/problems/non-overlapping-intervals/description/.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 1)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] < b[1]; // Sort by end time
             });

        int counter = 0;
        int prevEnd = intervals[0][1];
        ;
        for (int i = 1; i < intervals.size(); i++)
        {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // check for overlapping
            if (currStart < prevEnd)
            {
                counter++;
                // if its overlapping remove this, so prevEnd still kept same
            }
            else
            {
                prevEnd = currEnd;
            }
        }

        return counter;
    }
};