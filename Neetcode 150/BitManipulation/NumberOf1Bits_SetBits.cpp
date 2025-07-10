// https://leetcode.com/problems/number-of-1-bits/

// Time Complexity: O(k), where k = number of set bits
// Worst case (all bits 1): 32 iterations
class Solution
{
public:
    int hammingWeight(int n)
    {
        int setBits = 0;
        while (n)
        {
            n &= (n - 1);
            setBits++;
        }
        return setBits;
    }
};

// O(number of bits required to represent the number n)
// Worst case: O(32) - the loop runs up to 32 times.
// For a number n, the number of bits required to represent it in binary is:
// O(log₂(n))
class Solution
{
public:
    int hammingWeight(int n)
    {
        int setBits = 0;
        while (n > 0)
        {
            if (n & 1)
            { // Check if last bit is 1
                setBits++;
            }
            n = n >> 1; // Unsigned right shift
        }
        return setBits;
    }
};

// not optimal = O(log₂(n))
class Solution
{
public:
    // using method of converting a decimal to binary
    int hammingWeight(int n)
    {
        int setBits = 0;
        while (n > 0)
        {
            setBits += (n % 2);
            n = n / 2;
        }
        return setBits;
    }
};