// https://leetcode.com/problems/koko-eating-bananas/description/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // binary search is applied on the answer space, i.e., range of eating
    // speeds possible eating speed range = [1, max(piles)] time complexity =
    // O(n) * O(log(max_element in piles))
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // mid is the number of bananas Koko can eat in one hour
            long long totalEatingHrs = getTotalEatingHrs(piles, mid);
            // calculate total hours required at speed = mid

            if (totalEatingHrs <= h)
            {
                // if Koko can finish within h hours, try a smaller speed
                ans = mid;
                end = mid - 1;
            }
            else
            {
                // if totalEatingHrs > h => speed is too slow, try faster
                start = mid + 1;
            }
        }
        return ans;
    }

    // helper function to calculate total eating hours for a given speed
    long long getTotalEatingHrs(vector<int> &piles, int k)
    {
        long long noOfHrs = 0;
        for (int bananas : piles)
        {
            // using integer math to compute ceil(bananas / k)
            // if bananas = 10, k = 3 -> (10 + 2) / 3 = 4
            // noOfHrs += (bananas + k - 1LL) / k;
            noOfHrs += ceil(double(bananas) / double(k));
        }
        return noOfHrs;
    }
};
