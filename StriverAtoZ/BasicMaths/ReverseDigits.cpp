
// https://leetcode.com/problems/reverse-integer/
#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int n = 0;

        while (x != 0)
        {
            int lastDigit = x % 10;
            x = x / 10;

            // Check for overflow before multiplying by 10
            if (n > INT_MAX / 10 || n < INT_MIN / 10)
            {
                return 0;
            }
            n = n * 10 + lastDigit;
        }

        return n;
    }
};

// https://www.geeksforgeeks.org/problems/reverse-digit0316/1
// Constraints:
// 1 <= n <= 106
// time complexity = O(log10(N))
class Solution
{
public:
    int reverseDigits(int n)
    {
        int reverseNum = 0;
        while (n != 0)
        {
            int lastDigit = n % 10;
            reverseNum = (reverseNum * 10) + lastDigit;
            n = n / 10;
        }
        return reverseNum;
    }
};