// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            bool isPossible = canFinishEating(piles, h, mid);
            if (isPossible)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
    bool canFinishEating(vector<int> &piles, int maxTime, int eatinghrs)
    {
        long long totalTime = 0;
        for (auto bannanas : piles)
        {
            totalTime += ceil((double)bannanas / eatinghrs);
        }
        return totalTime <= maxTime;
    }
};