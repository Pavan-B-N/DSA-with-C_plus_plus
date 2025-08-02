// https://leetcode.com/problems/count-good-numbers/

class Solution
{
public:
    long long MOD = 1e9 + 7; // return it modulo 109 + 7.
    int countGoodNumbers(long long n)
    {
        // Even indices count = (n + 1) / 2 → choices: 5
        long long evens = (n + 1) / 2;
        // Odd indices count = n / 2 → choices: 4
        long long odds = n / 2;

        // inbuilt pow fails due to overflow and precision issues and doesn't handle MOD
        long long A = modPow(5, evens);
        long long B = modPow(4, odds);
        return static_cast<int>((A * B) % MOD);
    }
    // Fast modular exponentiation: computes x^n % MOD in O(log n)
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
};
