// https://www.geeksforgeeks.org/problems/set-kth-bit3724/1
/*
Input: n = 10, k = 2
Output: 14
Explanation: Binary representation of the given number 10 is: 1 0 1 0, number of bits in the binary reprsentation is 4. Thus 2nd bit from right is 0. The number after changing this bit to 1 is: 14(1 1 1 0).
*/
class Solution
{
public:
    int setKthBit(int n, int k)
    {
        return (n | (1 << k));
    }
};
