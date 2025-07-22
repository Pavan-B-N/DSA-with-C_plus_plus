// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
#include <cmath>
using namespace std;

class Solution
{
public:
    int nthRoot(int n, int m)
    {
        int start = 1;
        int end = m; // n can be 1, so m^1 = m

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int val = pow(mid, n);
            if (val == m)
            {
                return mid;
            }
            else if (val > m)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};