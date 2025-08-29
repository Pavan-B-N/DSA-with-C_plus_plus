// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
// tag: [favorite]
// tag: [noOptimal]
#include <vector>
#include <queue>
using namespace std;
// Most optimal we can say using binary Search

// better
// Time = O(n * log n) + O(k * log n) = O((n + k) * log n)
// Space = O(n)

class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        priority_queue<tuple<double, int, int>> maxHeap; // {gap, segmentLength, sectors}

        for (int i = 1; i < stations.size(); i++)
        {
            double gap = abs(stations[i] - stations[i - 1]);
            maxHeap.push({gap, gap, 1});
        }

        for (int i = 0; i < k; i++)
        {
            auto [gap, segmentLength, sectors] = maxHeap.top();
            maxHeap.pop();

            int newSector = sectors + 1;
            double newDist = (double)segmentLength / newSector;
            maxHeap.push({newDist, segmentLength, newSector});
        }

        auto [res, seg, sec] = maxHeap.top();
        // 18.6263 = 18.63
        // 18.6263 * 100 = 1862.63
        // round(1862.63) = 1863, rounds to the nearest integer.
        // 18.63
        return round(res*100)/100.0;
    }
};

// better
// Time = O(n * log n) + O(k * log n) = O((n + k) * log n)
// Space = O(n)
class Solution
{
public:
    struct Segment
    {
        double maxDist;
        int index;
        int sectors; // sectors = placedStations + 1

        // Max-heap: prioritize segment with largest maxDist
        bool operator<(const Segment &other) const
        {
            return maxDist < other.maxDist;
        }
    };

    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        priority_queue<Segment> maxHeap;

        // Initialize heap with original segments (1 sector each)
        // O(n * log n)
        for (int i = 0; i < n - 1; ++i)
        {
            double length = stations[i + 1] - stations[i];
            maxHeap.push({length, i, 1});
        }

        // Place k stations
        //  O(k * log n)
        for (int i = 0; i < k; ++i)
        {
            Segment top = maxHeap.top();
            maxHeap.pop();

            int newSectors = top.sectors + 1;
            double segmentLength = stations[top.index + 1] - stations[top.index];
            double newDist = segmentLength / newSectors;

            maxHeap.push({newDist, top.index, newSectors});
        }

        // Final max distance
        double result = maxHeap.top().maxDist;
        return round(result * 100.0) / 100.0; // round down to 2 decimals
    }
};

// brute force
// O(k * n)
class Solution
{
public:
    // Find the answer exactly to 2 decimal places or 10^-2
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        vector<int> placedStationsInSector(n - 1, 0); // Extra stations between each pair

        // Place k stations one by one
        for (int gasStation = 0; gasStation < k; ++gasStation)
        {
            int maxDistIdx = -1;
            double maxDist = 0.0;

            // Find segment with current max distance
            for (int j = 0; j < n - 1; ++j)
            {
                double segmentLength = stations[j + 1] - stations[j];
                double sectors = placedStationsInSector[j] + 1;
                double dist = segmentLength / sectors;

                if (dist > maxDist)
                {
                    maxDist = dist;
                    maxDistIdx = j;
                }
            }

            // Place one more station in that segment
            placedStationsInSector[maxDistIdx]++;
        }

        // After all stations are placed, compute final max distance
        double result = 0.0;
        for (int i = 0; i < n - 1; ++i)
        {
            double segmentLength = stations[i + 1] - stations[i];
            double sectors = placedStationsInSector[i] + 1;
            result = max(result, segmentLength / sectors);
        }

        // Round down to 2 decimal places
        return floor(result * 100.0) / 100.0;
    }
};