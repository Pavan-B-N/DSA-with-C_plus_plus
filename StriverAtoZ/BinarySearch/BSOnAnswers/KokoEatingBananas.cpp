// https://leetcode.com/problems/koko-eating-bananas/
#include <algorithm>
#include <vector>
using namespace std;

// lineaer = O(n* max_element)
// binary_seach = O(n * logn(max_element))
// so O(n * log(max(piles)))
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
            // Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
            // Return the minimum integer k such that she can eat all the bananas within h hours.
            if (isPossible)
            {
                end = mid - 1; // ans=mid
            }
            else
            {
                start = mid + 1;
            }
        }
        return start; // ans
    }
    bool canFinishEating(vector<int> &piles, int h, int bnanasCanEat)
    {
        long long totalTime = 0;
        for (auto bannanas : piles)
        {
            totalTime += ceil((double)bannanas / bnanasCanEat);
        }
        return totalTime <= h;
    }
};