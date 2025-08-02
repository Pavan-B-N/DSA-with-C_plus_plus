// https://leetcode.com/problems/divide-two-integers/
#include <iostream>
#include <climits>
// tag: [favorite]

// O(log(ldividend) × log(ldividend)) = O(log²N)
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1)
        {
            return INT_MIN;
        }
        // Determine the sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to avoid overflow
        long long ldividend = dividend;
        long long ldivisor = divisor;

        // Work with positive values only
        ldividend = abs(ldividend);
        ldivisor = abs(ldivisor);

        int result = 0;
        while (ldividend >= ldivisor)
        {
            long long temp = ldivisor;
            long long multiple = 1;
            while ((temp << 1) <= ldividend)
            {
                temp = temp << 1;
                multiple = multiple << 1;
            }
            ldividend -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
};
