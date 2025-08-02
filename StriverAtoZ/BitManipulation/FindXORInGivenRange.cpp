// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

// TLE
class Solution
{
public:
    int findXOR(int l, int r)
    {
        int ans = 0;
        for (int i = l; i <= r; i++)
        {
            ans ^= i;
        }
        return ans;
    }
};
/*
| n | XOR(1 to n) |
| - | ----------- |
| 1 | 1           |
| 2 | 3 (1^2)     |
| 3 | 0 (1^2^3)   |
| 4 | 4 (1^2^3^4) |
| 5 | 1           |
| 6 | 7           |
| 7 | 0           |
| 8 | 8           |
*/
// O(1)
class Solution
{
public:
    int findXOR(int l, int r)
    {
        int a = findXor1toN(l - 1); // 1 to L
        int b = findXor1toN(r);     // 1 to R
        return a ^ b;
    }
    // based on continuous xor observation from 1 to N in the group of 4
    int findXor1toN(int n)
    {
        if (n % 4 == 1)  
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }
};