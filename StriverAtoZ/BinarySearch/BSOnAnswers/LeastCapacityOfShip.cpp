// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include <vector>
#include <numeric> //accumulate
#include <algorithm>
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int start = *max_element(weights.begin(), weights.end());
        // accumulate = sum of elements
        int end = accumulate(weights.begin(), weights.end(), 0);
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isPossibleToShip(weights, days, mid))
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
    bool isPossibleToShip(vector<int> &weights, int maxDays, int capacity)
    {
        int requiredDays = 1; // first shipment on day 1.
        int currCapacity = 0;
        for (int weight : weights)
        {
            if (currCapacity + weight > capacity)
            {
                currCapacity = 0;
                requiredDays++;
            }
            currCapacity += weight;
        }
        return requiredDays <= maxDays;
    }
};