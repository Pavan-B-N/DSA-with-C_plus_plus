// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
/*
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
*/
#include <vector>
using namespace std;

class Solution
{
public:
    int nthRoot(int n, int m)
    {
        int start = 1;
        int end = m;

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