// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

class Solution
{
public:
    // logn
    int setBit(int n)
    {
        int num = 1;
        while ((n & num) != 0)
        {
            num = num << 1;
        }
        return n | num;
    }
};

class Solution
{
public:
    // 1
    int setBit(int n)
    {
        return n | (~n & (n + 1));
        // to unset rightmost set bit = n & n-1
    }
};