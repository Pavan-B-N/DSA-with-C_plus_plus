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
            {   // marked as prime
                // so mark, multiple of this number as not prime
                for (int j = i * 2; j < n; j += i)
                {
                    arr[j] = false;
                }
            }
        }

        // end of  Sieve of Eratosthenes

        int counter = 0;
        for (int i = 2; i < n; ++i)
        {
            if (arr[i])
                ++counter;
        }

        return counter;
    }
};
