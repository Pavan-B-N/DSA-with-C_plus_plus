// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < start.size(); i++)
        {
            meetings.push_back({end[i], start[i]});
        }

        sort(meetings.begin(), meetings.end());

        int maxMeets = 0;
        int prevEnd = -1;

        for (auto meeting : meetings)
        {
            // [endTime,startTime]
            int startTime = meeting.second;
            int endTime = meeting.first;

            if (startTime > prevEnd)
            {
                maxMeets++;
                prevEnd = endTime;
            }
        }
        return maxMeets;
    }
};