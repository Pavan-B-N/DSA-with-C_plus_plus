// https://leetcode.com/problems/reverse-bits/
#include <iostream>
using namespace std;
// O(32) More efficient and idiomatic
// because no m,ultiplication and division involves
// bit level modification is faster
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t rev = 0;
        for (int i = 0; i < 32; i++)
        {
            rev = (rev << 1) | (n & 1);
            n >>= 1;
        }
        return rev;
    }
};

// O(32)
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t rev = 0;
        for (int i = 0; i < 32; i++)
        {
            rev = rev * 2 + (n % 2); // Add the last bit
            n = n / 2;               // Shift right
        }
        return rev;
    }
};
