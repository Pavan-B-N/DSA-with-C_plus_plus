// https://www.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1
#include <string>
using namespace std;

class Solution
{
public:
    int binaryToDecimal(string &b)
    {
        int powOf2 = 1;
        int ans = 0;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            if (b[i] == '1')
            {
                ans += powOf2;
            }
            powOf2 *= 2;
        }
        return ans;
    }
};