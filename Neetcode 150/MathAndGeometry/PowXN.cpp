// https://leetcode.com/problems/powx-n/
#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        long long N = n; // promote to long long to avoid overflow
        bool isNeg = N < 0;
        N = abs(N); // long long is safe, but not int for n= -2147483648

        // while (N > 0)
        // {
        //     if (N % 2 == 1)
        //         ans *= x;
        //     x *= x;
        //     N /= 2;
        // }
        while (N > 0)
        {
            // n is even
            if (N % 2 == 0)
            {
                x = x * x;
                N = N / 2;
            }
            else
            {
                ans = ans * x;
                N--;
            }
        }

        return isNeg ? 1 / ans : ans;
    }
};
