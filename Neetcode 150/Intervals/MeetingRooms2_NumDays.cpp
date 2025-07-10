// https://neetcode.io/problems/meeting-schedule-ii?list=neetcode150
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// Problem Statement
/*
Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of days required to schedule all meetings without any conflicts.

Note: (0,8),(8,10) is not considered a conflict at 8.

Example 1:

Input: intervals = [(0,40),(5,10),(15,20)]

Output: 2
Explanation:
day1: (0,40)
day2: (5,10),(15,20)
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

// O(nlogn)
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return 0;
        
        // Sort by start time
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
             { return a.start < b.start; });

        // Min-heap to track the end times
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Add the first meeting end time
        minHeap.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); i++)
        {
            // If current meeting can use the same room (i.e. starts after previous ends)
            if (intervals[i].start >= minHeap.top())
            {
                minHeap.pop(); // Remove the room that's free
            }

            // Add the current meeting's end time to heap
            minHeap.push(intervals[i].end);
        }

        return minHeap.size(); // Number of rooms needed
    }
};

// Inefficient (O(n²) in worst case)
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return 0;

        // Sort intervals by start time
        // soting = O(n logn)
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
             { return a.start < b.start; });

        int roomCount = 0;

        // Work on a copy to preserve original input
        vector<Interval> remaining = intervals;

        while (!remaining.empty())
        {
            roomCount++;
            removeMaxMeetingsFromOneRoom(remaining);
        }

        return roomCount;
    }

private:
    // Remove the maximum number of non-overlapping meetings that can fit in one room
    void removeMaxMeetingsFromOneRoom(vector<Interval> &intervals)
    {
        vector<bool> toRemove(intervals.size(), false);
        int n = intervals.size();

        int freeTime = intervals[0].end;
        toRemove[0] = true;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i].start >= freeTime)
            {
                toRemove[i] = true;
                freeTime = intervals[i].end;
            }
        }

        // Erase selected intervals in reverse to avoid shifting issues
        for (int i = n - 1; i >= 0; i--)
        {
            if (toRemove[i])
            {
                intervals.erase(intervals.begin() + i);
            }
        }
    }
};
