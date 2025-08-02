// https://leetcode.com/problems/powx-n/

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long exp = n; // to safely handle INT_MIN
        if (exp < 0)
        {
            x = 1 / x;
            exp = -exp; // n = INT_MIN; // -2147483648
        }
        return helper(x, exp);
    }
    double helper(double x, long long n)
    {
        if (n <= 0)
        {
            return 1;
        }
        if (n % 2 == 0)
        {
            return myPow(x * x, n / 2);
        }
        else
        {
            return x * myPow(x, n - 1);
        }
    }
};

long long MOD = 1e9 + 7; // return it modulo 109 + 7.
long long modPow(long long x, long long n)
{
    long long res = 1;
    x %= MOD;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1; // n/2
    }
    return res;
}