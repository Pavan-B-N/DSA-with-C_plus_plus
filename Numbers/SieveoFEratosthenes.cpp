// https://leetcode.com/problems/count-primes/
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        //  Sieve of Eratosthenes
        vector<bool> arr(n, true);
        arr[0] = false;
        arr[1] = false;

        for (int i = 2; i * i < n; ++i)
        {
            if (arr[i])
            {
                // All numbers less than i * i will have already been marked by smaller primes.
                // Starting from 2 * i causes unnecessary marking of numbers that were already handled by smaller factors.
                for (int j = i * i; j < n; j += i)
                {
                    arr[j] = false;
                }
            }
        }

        int counter = 0;
        for (int i = 2; i < n; ++i)
        {
            if (arr[i])
                ++counter;
        }

        return counter;
    }
};
