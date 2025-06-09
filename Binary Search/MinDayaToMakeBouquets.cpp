// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
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
            if (canMakeBouquets(bloomDay, m, k, mid))
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

    // O(n)
    bool canMakeBouquets(vector<int> &bloomDay, int m, int k, int day)
    {
        int consecutive = 0, bouquets = 0;
        for (int flower : bloomDay)
        {
            if (flower <= day)
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