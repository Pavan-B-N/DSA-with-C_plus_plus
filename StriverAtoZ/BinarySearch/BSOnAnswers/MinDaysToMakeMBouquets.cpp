// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // m = bouquets
    // To make a bouquet, you need to use k adjacent flowers from the garden.
    // Total time = O(n * log(max - min))
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        // edge case
        if (1LL * m * k > n)
        {
            return -1;
        }
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            bool isPossible = canMakeBouquets(bloomDay, m, k, mid);
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

    // O(n)
    bool canMakeBouquets(vector<int> &bloomDay, int m, int k, int day)
    {
        int consecutive = 0, bouquets = 0;
        for (int flowerBloomDay : bloomDay)
        {
            if (flowerBloomDay <= day)
            {
                consecutive++;
            }
            else
            {
                bouquets += consecutive / k;
                consecutive = 0;
            }
        }
        bouquets += consecutive / k;
        return bouquets >= m;
    }
};