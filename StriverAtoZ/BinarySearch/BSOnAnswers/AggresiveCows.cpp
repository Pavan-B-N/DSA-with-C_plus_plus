// https://www.geeksforgeeks.org/problems/aggressive-cows/1
// tag: [favorite]
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();

        sort(stalls.begin(), stalls.end());
        int start = 1;
        int end = stalls[n - 1] - stalls[0];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossibleToPlaceCows(stalls, mid, k))
            {
                // ans=mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return end; // ans
    }

    bool isPossibleToPlaceCows(vector<int> &stalls, int minDistance, int k)
    {
        int n = stalls.size();
        int cowsPlaced = 1;
        int lastCowPosition = 0;
        for (int i = 1; i < n; i++)
        {
            int diff = stalls[i] - stalls[lastCowPosition];
            if (diff >= minDistance)
            {
                lastCowPosition = i;
                cowsPlaced++;
            }
        }

        return cowsPlaced >= k;
    }
};