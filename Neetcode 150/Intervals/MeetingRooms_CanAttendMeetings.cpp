// https://neetcode.io/problems/meeting-schedule?list=neetcode150
#include <vector>
#include <algorithm>

using namespace std;
/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), determine if a person could add all meetings to their schedule without any conflicts.

Input: intervals = [(0,30),(5,10),(15,20)]

Output: false

*/
// Definition of Interval:
class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

// Time Complexity: O(n log n) — due to sorting.
// Space Complexity: O(1) — if sorting in-place.
class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        int n = intervals.size();
        if (n == 0)
        {
            return true;
        }
        // Sort by start time
        // custom class like Interval, the compiler doesn’t know how to compare two objects
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
             { return a.start < b.start; });

        int freeTime = intervals[0].end;
        for (int i = 1; i < n; i++)
        {
            // If there is an overlap
            if (intervals[i].start < freeTime)
            {
                return false;
            }
            freeTime = intervals[i].end;
        }
        return true;
    }
};