// https://www.geeksforgeeks.org/problems/prime-factors5052/1
#include <vector>
#include <algorithm>
using namespace std;
// bruteForce = generating all factors and pick only prime = O(sqrt(n) * sqrt(n)) + O(k log k) due to sorting

// optimal = by diving the the n till possible
// O(sqrt(n) + log(n))


class Solution
{
public:
    // O(sqrt(n) * sqrt(n)) + O(k log k)
    // T(n) = O(n) + O(k log k)
    vector<int> primeFac(int n)
    {
        vector<int> res;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (isPrime(i))
                    res.push_back(i);
                if (i != n / i && isPrime(n / i))
                    res.push_back(n / i);
            }
        }
        sort(res.begin(), res.end()); // O(k log k)

        return res;
    }

    bool isPrime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};


// O(sqrt(n) + log(n))
class Solution
{
public:
    vector<int> primeFac(int n)
    {
        vector<int> res;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                res.push_back(i);

                // divide till we can
                // marking all multiples like in sieve of erosthostis
                while (n % i == 0)
                {
                    n = n / i; // due to this it takes log(n)
                }
            }
        }
        if (n != 1)
            res.push_back(n);
        return res;
    }
};