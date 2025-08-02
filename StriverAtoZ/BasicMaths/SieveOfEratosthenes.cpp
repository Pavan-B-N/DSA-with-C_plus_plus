// https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n log (logn)), mathematically proven
class Solution
{
public:
    vector<int> sieve(int n)
    {
        vector<bool> sieve(n + 1, true);
        sieve[1] = false;
        for (int i = 2; i <= n; i++)
        {
            // mark multiples as false
            if (sieve[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        vector<int> res;
        for (int i = 2; i <= n; i++)
        {
            if (sieve[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};