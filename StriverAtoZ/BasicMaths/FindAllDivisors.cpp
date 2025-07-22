// https://www.naukri.com/code360/problems/find-all-divisors-of-a-natural-number_5587903
#include <algorithm>
#include <vector>
using namespace std;

// O(k log k)
// O(k log k) for sorting (k ≤ 2√n)
vector<int> getAllDivisors(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end()); // O(k log k)
    return res;
}