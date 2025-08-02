// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
/*
Given two positive integer n and  k, check if the kth index bit of n is set or not.
Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.

Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
*/

// Time Complexity: O(1)

// left shift
class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        return (n & (1 << k)) != 0;
    }
};

// right shift
class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        return (n >> k & 1);
    }
};