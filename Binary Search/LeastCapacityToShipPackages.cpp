// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <vector>
#include <algorithm>
#include <numeric> // accumulate to find sum of elements
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

    bool isPossibleToShip(vector<int> &weights, int days, int capacity)
    {
        int requiredDays = 1; // start with 1 day
        int total = 0;

        for (int weight : weights)
        {
            if (total + weight > capacity)
            {
                requiredDays++;
                total = 0;
            }
            total += weight;
        }

        return requiredDays <= days;
    }
};