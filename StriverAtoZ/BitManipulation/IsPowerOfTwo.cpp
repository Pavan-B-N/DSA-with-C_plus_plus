// https://leetcode.com/problems/power-of-two/description/

#include <climits>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        // INT_MIN - 1 = -Val - 1 = - Val +1 which caused overflow
        // It’s the negative of a power of 2.
        if (n == 0 || n == INT_MIN)
            return false;
        return (n & (n - 1)) == 0;
    }
};