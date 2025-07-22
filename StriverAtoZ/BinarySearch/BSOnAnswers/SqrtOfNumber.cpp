// https://leetcode.com/problems/sqrtx/

// O(logn)
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        int start = 1;
        int end = x / 2;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            if (mid * mid <= x)
            {
                // ans= mid
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end; // ans
    }
};

// TLE
// O(n/2) = o(n)
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        int root = 1;
        for (long long i = 2; i <= x / 2; i++)
        {
            if (i * i <= x)
            {
                root = i;
            }
        }
        return root;
    }
};